#include <SWI-Prolog.h>
#include <SWI-Stream.h>
#include <stdbool.h>
#include <stdio.h>
#include <raylib.h>


static Color get_macro_color(term_t colorTerm_pl) {
	if (PL_unify_atom_chars(colorTerm_pl, "lightgray")) return LIGHTGRAY;
	else if (PL_unify_atom_chars(colorTerm_pl, "gray")) return GRAY;
	else if (PL_unify_atom_chars(colorTerm_pl, "darkgray")) return DARKGRAY;
	else if (PL_unify_atom_chars(colorTerm_pl, "yellow")) return YELLOW;
	else if (PL_unify_atom_chars(colorTerm_pl, "gold")) return GOLD;
	else if (PL_unify_atom_chars(colorTerm_pl, "orange")) return ORANGE;
	else if (PL_unify_atom_chars(colorTerm_pl, "pink")) return PINK;
	else if (PL_unify_atom_chars(colorTerm_pl, "red")) return RED;
	else if (PL_unify_atom_chars(colorTerm_pl, "maroon")) return MAROON;
	else if (PL_unify_atom_chars(colorTerm_pl, "green")) return GREEN;
	else if (PL_unify_atom_chars(colorTerm_pl, "lime")) return LIME;
	else if (PL_unify_atom_chars(colorTerm_pl, "darkgreen")) return DARKGREEN;
	else if (PL_unify_atom_chars(colorTerm_pl, "skyblue")) return SKYBLUE;
	else if (PL_unify_atom_chars(colorTerm_pl, "blue")) return BLUE;
	else if (PL_unify_atom_chars(colorTerm_pl, "darkblue")) return DARKBLUE;
	else if (PL_unify_atom_chars(colorTerm_pl, "purple")) return PURPLE;
	else if (PL_unify_atom_chars(colorTerm_pl, "violet")) return VIOLET;
	else if (PL_unify_atom_chars(colorTerm_pl, "darkpurple")) return DARKPURPLE;
	else if (PL_unify_atom_chars(colorTerm_pl, "beige")) return BEIGE;
	else if (PL_unify_atom_chars(colorTerm_pl, "brown")) return BROWN;
	else if (PL_unify_atom_chars(colorTerm_pl, "darkbrown")) return DARKBROWN;
	else if (PL_unify_atom_chars(colorTerm_pl, "white")) return WHITE;
	else if (PL_unify_atom_chars(colorTerm_pl, "black")) return BLACK;
	else if (PL_unify_atom_chars(colorTerm_pl, "blank")) return BLANK;
	else if (PL_unify_atom_chars(colorTerm_pl, "magenta")) return MAGENTA;
	else if (PL_unify_atom_chars(colorTerm_pl, "raywhite")) return RAYWHITE;
	//else
	//else return (Color) {(rand() % 256),(rand() % 256),(rand() % 256),(rand() % 256)};
	else return BLACK;
}

static Color get_color(term_t colorTerm_pl) {
	
	if (PL_is_atom(colorTerm_pl)) return get_macro_color(colorTerm_pl);
	
	term_t rgba_pl = PL_new_term_refs(4);	
	int rgba_c[4];
	
	for (int i = 0; i < 4; i++) {
		PL_get_arg(i+1, colorTerm_pl, (rgba_pl+i));
		PL_get_integer( (rgba_pl+i), (rgba_c+i) );
	}
	
	Color color = (Color) {rgba_c[0], rgba_c[1], rgba_c[2], rgba_c[3]};
	
	return color; 
	
}


static foreign_t pl_test_get_Color(term_t colorTerm_pl) {
	// https://github.com/raysan5/raylib/blob/773e3f5f9fd39a3f968f29d1f7e6d9ea491b7154/examples/others/rlgl_standalone.c#L83
	/*
	typedef struct Color {
		unsigned char r;        // Color red value
		unsigned char g;        // Color green value
		unsigned char b;        // Color blue value
		unsigned char a;        // Color alpha value
	} Color;
	*/
	printf("Entered pl_test_get_Color\n");
	Color color = get_color(colorTerm_pl);
	printf("r is %d, g is %d, b is %d, a is %d\n", color.r, color.g, color.b, color.a);
	return true;
}

static foreign_t 
pl_InitWindow(term_t width_pl, term_t height_pl, term_t title)
{ char *s;
	int width_c;
	int height_c;
	printf("No crash yet 1");
	PL_get_integer_ex(width_pl, &width_c);
	printf("No crash yet 2");
	PL_get_integer_ex(height_pl, &height_c);
	printf("No crash yet 3");
    if ( PL_get_chars(title, &s, CVT_ALL|REP_UTF8) )
	    InitWindow(width_c, height_c, s);
    else 
		InitWindow(width_c, height_c, "[Could not load title]");
		
	return true;
}

static foreign_t 
pl_SetTargetFPS(term_t fps_pl)
{ 
	int fps_c;
	
	printf("fps_pl %s integer\n", 
	PL_is_integer(fps_pl)
	? "IS" : "is NOT");
	
	printf("fps_pl -> fps_c extraction %s\n",
	PL_get_integer(fps_pl, &fps_c)
	? "SUCCEEDED" : "FAILED");
	
	printf("value of fpc_c=%d\n", fps_c);
	SetTargetFPS(fps_c);
	return true;
}

static foreign_t 
pl_BeginDrawing(void)
{ 
	BeginDrawing();
	return true;
}

static foreign_t 
pl_ClearBackground(term_t color_pl)
{ 
	ClearBackground( get_color(color_pl) );
	return true;
}

static foreign_t 
pl_ClearBackground_simplified(void)
{ 
	ClearBackground( RAYWHITE );
	return true;
}

static foreign_t 
pl_DrawText_simplified(
	term_t text_pl, 
	term_t posX_pl, 
	term_t posY_pl, 
	term_t fontSize_pl)
{ // simplified no color 
	char *text_c;
	int posX_c;
	int posY_c;
	int fontSize_c;
	PL_get_integer_ex(posX_pl, &posX_c);
	PL_get_integer_ex(posY_pl, &posY_c);
	//printf("posX is %d and posY is %d", posX_c, posY_c);
	PL_get_integer_ex(fontSize_pl, &fontSize_c);
    if (PL_get_chars(text_pl, &text_c, CVT_ALL|REP_UTF8) ) {
		DrawText(text_c, posX_c, posY_c, fontSize_c, LIGHTGRAY);
	}
	else {
		DrawText("Problem getting text_pl.", posX_c, posY_c, fontSize_c, LIGHTGRAY);
	}
	return true;
}

static foreign_t 
pl_DrawText(
	term_t text_pl, 
	term_t posX_pl, 
	term_t posY_pl, 
	term_t fontSize_pl,
	term_t colorTerm_pl)
{ 
	char *text_c;
	int posX_c;
	int posY_c;
	int fontSize_c;
	Color color;
	PL_get_integer_ex(posX_pl, &posX_c);
	PL_get_integer_ex(posY_pl, &posY_c);
	PL_get_integer_ex(fontSize_pl, &fontSize_c);
	color = get_color(colorTerm_pl);
    if (PL_get_chars(text_pl, &text_c, CVT_ALL|REP_UTF8) ) {
		DrawText(text_c, posX_c, posY_c, fontSize_c, color);
	}
	else {
		DrawText("Problem getting text_pl.", posX_c, posY_c, fontSize_c, color);
	}
	return true;
}

static foreign_t 
pl_EndDrawing(void)
{ 
	EndDrawing();
	return true;
}

static foreign_t 
pl_WindowShouldClose(void)
{ 
	return WindowShouldClose();
}

static foreign_t 
pl_CloseWindow(void)
{ 
	CloseWindow();
	return true;
}

static foreign_t 
pl_IsKeyPressed(term_t key_pl) {
	if (!PL_is_ground(key_pl)) return false;
	if (PL_is_atom(key_pl)) {
		if (PL_unify_atom_chars(key_pl, "key_right")) return IsKeyPressed(KEY_RIGHT);
		if (PL_unify_atom_chars(key_pl, "key_left")) return IsKeyPressed(KEY_LEFT);
		if (PL_unify_atom_chars(key_pl, "key_down")) return IsKeyPressed(KEY_DOWN);
		if (PL_unify_atom_chars(key_pl, "key_up")) return IsKeyPressed(KEY_UP);
		if (PL_unify_atom_chars(key_pl, "key_backspace")) return IsKeyPressed(KEY_BACKSPACE);
		if (PL_unify_atom_chars(key_pl, "key_enter")) return IsKeyPressed(KEY_ENTER);
		//else
		return false;
	} else {
		int key_c;
		if (PL_get_integer(key_pl, &key_c)) return IsKeyPressed(key_c);
		else return false;
	}
}


install_t
install_raylib55_pro_interface(void)
{ 
PL_register_foreign("init_window", 3, pl_InitWindow, 0);
PL_register_foreign("set_target_FPS", 1, pl_SetTargetFPS, 0);
PL_register_foreign("begin_drawing", 0, pl_BeginDrawing, 0);
PL_register_foreign("clear_background", 1, pl_ClearBackground, 0);
PL_register_foreign("clear_background_simplified", 0, pl_ClearBackground_simplified, 0);
PL_register_foreign("draw_text_simplified", 4, pl_DrawText_simplified, 0);
PL_register_foreign("draw_text", 5, pl_DrawText, 0);
PL_register_foreign("end_drawing", 0, pl_EndDrawing, 0);
PL_register_foreign("window_should_close", 0, pl_WindowShouldClose, 0);
PL_register_foreign("close_window", 0, pl_CloseWindow, 0);
PL_register_foreign("test_get_Color", 1, pl_test_get_Color, 0);
PL_register_foreign("is_key_pressed", 1, pl_IsKeyPressed, 0);
}