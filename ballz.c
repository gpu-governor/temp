#include"raylib.h"
#include<stdio.h>
#include"game.h"
const int width = 1150;
const int height = 720;
	#define BALL_COUNT 17 // Number of balls including cue ball
	#define ROW_SPACING 39 // Vertical distance between rows
	#define BALL_SPACING 40 // Horizontal spacing between balls in a row


// =============================MAIN FUNCTION ======================================

int main(){
	init(width,height);
	Asset table = load_asset("Assets/table.png", 20,20,0.24f);
	Asset cue = load_asset("Assets/cue.png", 150, 150, 0.2f);
	Asset triangle = load_asset("Assets/triangle.png", 400, 150, 0.2f);
	// balls
	// Asset balls[BALL_COUNT];
	// balls[1] = load_asset("Assets/ball_1.png", 0, 50, 0.2f);
	// balls[2] = load_asset("Assets/ball_2.png", 10, 50, 0.2f);
	// balls[3] = load_asset("Assets/ball_3.png", 20, 50, 0.2f);
	// balls[4] = load_asset("Assets/ball_4.png", 30, 50, 0.2f);
	// balls[5] = load_asset("Assets/ball_5.png", 40, 50, 0.2f);
	// balls[6] = load_asset("Assets/ball_6.png", 50, 50, 0.2f);
	// balls[7] = load_asset("Assets/ball_7.png", 60, 50, 0.2f);
	// balls[8] = load_asset("Assets/ball_8.png", 60, 50, 0.2f);
	// balls[9] = load_asset("Assets/ball_9.png", 60, 50, 0.2f);
	// balls[10] = load_asset("Assets/ball_10.png", 60, 50, 0.2f);
	// balls[11] = load_asset("Assets/ball_11.png", 60, 50, 0.2f);
	// balls[12] = load_asset("Assets/ball_12.png", 60, 50, 0.2f);
	// balls[13] = load_asset("Assets/ball_13.png", 60, 50, 0.2f);
	// balls[14] = load_asset("Assets/ball_14.png", 60, 50, 0.2f);
	// balls[15] = load_asset("Assets/ball_15.png", 60, 50, 0.2f);
	// balls[16] = load_asset("Assets/ball_16.png", 780,300, 0.2f);


// Define offsets to control the triangle position
int offsetX = 250; // Center X position of the triangle
int offsetY = 300; // Center Y position of the triangle

Asset balls[BALL_COUNT];
int ballIndex = 1; // Start from ball 1

for (int row = 5; row >= 1; row--) { // Start from the widest row
    int ballsInRow = row;
    int startY = offsetY - (BALL_SPACING * (ballsInRow - 1)) / 2; // Center each row vertically
    int x = offsetX + ROW_SPACING * (5 - row); // Horizontal position for this row
    
    for (int i = 0; i < ballsInRow; i++) {
        int y = startY + i * BALL_SPACING;
        
        // Create filename for the current ball
        char filename[50];
        sprintf(filename, "Assets/ball_%d.png", ballIndex);

        // Load the asset at the adjusted x, y position
        balls[ballIndex] = load_asset(filename, x, y, 0.3f);
        
        ballIndex++;
    }
}

// Position cue ball separately
balls[16] = load_asset("Assets/ball_16.png", 780, 300, 0.3f);

	

	// collision rectangles walls
	Rectangle topleft = {110,20, 420, 70};
	Rectangle topright = {600,20, 420, 70};
	Rectangle bottomleft = {110,567, 420, 70};
	Rectangle bottomright = {600,567, 420, 70};	
	Rectangle sideright = {20,110, 70, 420};
	Rectangle sideleft = {1040,110,70,420};

	// collisions rectangles pockets hole
	Rectangle topleftpocket = {20,20,80,80};
	Rectangle toprightpocket = {1040,20,80,80};
	Rectangle topmidpocket = {520,20,80,80};
	Rectangle bottomleftpocket = {20,567,80,80};
	Rectangle bottomrightpocket = {1040,567,80,80};
	Rectangle bottommidpocket = {520,567,80,80};
		
	while(!WindowShouldClose()){
		BeginDrawing();
		ClearBackground(RAYWHITE);
		 render_asset(table);
		 render_asset(cue);
		 // render_asset(triangle);
		 for (int i = 0; i< BALL_COUNT+1; i++){
		 	render_asset(balls[i]);
		 }

		DrawText("gerr",780,300,20,RED);
		
		// // walls
		//  DrawRectangleRec(topleft,BLUE);
		//  DrawRectangleRec(topright,BLUE);
		//  DrawRectangleRec(bottomright,BLUE);
		//  DrawRectangleRec(bottomleft,BLUE);
		//  DrawRectangleRec(sideleft,BLUE);
		//  DrawRectangleRec(sideright,BLUE);
		//  // pockets
		//  DrawRectangleRec(topleftpocket,RED);
		//  DrawRectangleRec(toprightpocket,RED);
		//  DrawRectangleRec(topmidpocket,RED);
		//  DrawRectangleRec(bottomleftpocket,RED);
		//  DrawRectangleRec(bottomrightpocket,RED);
		//  DrawRectangleRec(bottommidpocket,RED);
		// TODO GAME LOGIC
		EndDrawing();
	}
	// cleanup 
	for (int i= 0; i <BALL_COUNT+1; i++){
		UnloadTexture(balls[i].texture);
	}
	UnloadTexture(table.texture);
	UnloadTexture(cue.texture);
	UnloadTexture(triangle.texture);
	quit();
	return 0;
}
