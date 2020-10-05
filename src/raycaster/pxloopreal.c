/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pxloopreal.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/01 21:30:30 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/05 22:31:32 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <extra.h>

int		pxloopreal(t_base *b)
{
	double	planeX = 0;
	double	planeY = 0.66; //the 2d raycaster version of camera plane
	int		x;

	x = 0;
	while (x < b->res.x)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / (double)b->res.x - 1; //x-coordinate in camera space
		double raydirx = b->map.sp_dir.x + planeX * cameraX;
		double raydiry = b->map.sp_dir.y + planeY * cameraX;
		//which box of the map we're in
		int mapX = b->map.sp_pos.x;
		int mapY = b->map.sp_pos.y;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = fabs(1 / raydirx);
		double deltaDistY = fabs(1 / raydiry);
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
		if (raydirx < 0)
		{
			stepX = -1;
			sideDistX = (b->map.sp_pos.x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - b->map.sp_pos.x) * deltaDistX;
		}
		if (raydiry < 0)
		{
			stepY = -1;
			sideDistY = (b->map.sp_pos.y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - b->map.sp_pos.y) * deltaDistY;
		}
		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (b->map.ptr[mapX][mapY] > 0)
				hit = 1;
		}
		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if (side == 0)
			perpWallDist = (mapX - b->map.sp_pos.x + (1 - stepX) / 2) / raydirx;
		else
			perpWallDist = (mapY - b->map.sp_pos.y + (1 - stepY) / 2) / raydiry;

		//Calculate height of line to draw on screen
		int lineHeight = (int)(b->res.y / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + b->res.y / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + b->res.y / 2;
		if (drawEnd >= b->res.y)
			drawEnd = b->res.y - 1;

		//choose wall color
		ColorRGB color;
		switch(b->map.ptr[mapX][mapY])
		{
			case 1:  color = RGB_Red;    break; //red
			case 2:  color = RGB_Green;  break; //green
			case 3:  color = RGB_Blue;   break; //blue
			case 4:  color = RGB_White;  break; //white
			default: color = RGB_Yellow; break; //yellow
		}

		//give x and y sides different brightness
		if (side == 1)
			{color = color / 2;}

		//draw the pixels of the stripe as a vertical line
		verLine(x, drawStart, drawEnd, color);
		x++;
	}
	
	redraw();
	cls();

	//speed modifiers
	double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
	double rotSpeed = frameTime * 3.0; //the constant value is in radians/second
	readKeys();
	//move forward if no wall in front of you
	if(keyDown(SDLK_UP))
	{
	  if(b->map.ptr[(int)(b->map.sp_pos.x + b->map.sp_dir.x * moveSpeed)][(int)(b->map.sp_pos.y)] == false) b->map.sp_pos.x += b->map.sp_dir.x * moveSpeed;
	  if(b->map.ptr[b->map.sp_pos.x][(int)(b->map.sp_pos.y + b->map.sp_dir.y * moveSpeed)] == false) b->map.sp_pos.y += b->map.sp_dir.y * moveSpeed;
	}
	//move backwards if no wall behind you
	if(keyDown(SDLK_DOWN))
	{
	  if(b->map.ptr[(int)(b->map.sp_pos.x - b->map.sp_dir.x * moveSpeed)][(int)(b->map.sp_pos.y)] == false) b->map.sp_pos.x -= b->map.sp_dir.x * moveSpeed;
	  if(b->map.ptr[(int)(b->map.sp_pos.x)][(int)(b->map.sp_pos.y - b->map.sp_dir.y * moveSpeed)] == false) b->map.sp_pos.y -= b->map.sp_dir.y * moveSpeed;
	}
	//rotate to the right
	if(keyDown(SDLK_RIGHT))
	{
	  //both camera direction and camera plane must be rotated
	  double olddirx = b->map.sp_dir.x;
	  b->map.sp_dir.x = b->map.sp_dir.x * cos(-rotSpeed) - b->map.sp_dir.y * sin(-rotSpeed);
	  b->map.sp_dir.y = olddirx * sin(-rotSpeed) + b->map.sp_dir.y * cos(-rotSpeed);
	  double oldPlaneX = planeX;
	  planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
	  planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
	}
	//rotate to the left
	if(keyDown(SDLK_LEFT))
	{
	  //both camera direction and camera plane must be rotated
	  double olddirx = b->map.sp_dir.x;
	  b->map.sp_dir.x = b->map.sp_dir.x * cos(rotSpeed) - b->map.sp_dir.y * sin(rotSpeed);
	  b->map.sp_dir.y = olddirx * sin(rotSpeed) + b->map.sp_dir.y * cos(rotSpeed);
	  double oldPlaneX = planeX;
	  planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
	  planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
	}
}