:- module(raylib55, [
	init_window/3, 
	set_target_FPS/1, 
	begin_drawing/0, 
	clear_background/1,
	%clear_background_simplified/0,
	draw_text_simplified/4,
	draw_text/5,
	end_drawing/0,
	window_should_close/0,
	close_window/0,
	test_get_Color/1,
	is_key_pressed/1
	]).
:- use_foreign_library(foreign(raylib55_pro_interface)).

user:term_expansion(raywhite, color(245, 245, 245, 255)).