//
//  Created by Matt Hartley on 21/04/2026.
//  Copyright 2026 GiantJelly. All rights reserved.
//

#ifndef SYS_PC_H
#define SYS_PC_H

#include <GL/gl.h>
#include <core/core.h>
#include <core/video.h>
#include "r_render.h"


#define LEVEL_GRID_SIZE 64
typedef struct {
	bool_t level[LEVEL_GRID_SIZE*LEVEL_GRID_SIZE];
} game_t;

typedef struct {
	window_t window;
	uint32_t* framebuffer;
	float* depthbuffer;
	GLuint framebufferTex;

	allocator_t assetArena;
	mesh_t cryoMesh;
	model_t cryoModel;
	model_t cubeModel;
	model_t testboxModel;
	model_t corridorDefaultModel;

	double sysTime;
	double sysTimePrev;
	float deltaTime;
	float gameTime;

	game_t game;
} state_t;

state_t* GetState();
file_data_t* Sys_LoadFile(allocator_t* allocator, char* path);
texture_t R_LoadTexture(char* path);
model_t GenerateModelFromQuads(mvertex_t* vertices, int quadCount, char* textureFile);


#endif
