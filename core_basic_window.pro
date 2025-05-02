
:- ['raylib55.pro'].

get_color(is_crazy, BGColor) :- 
	random_member(BGColor, [raywhite, black, blue, purple]).
get_color(IsCrazy, raywhite) :- dif(IsCrazy, is_crazy).

main_experimental(IsCrazy) :-
    ScreenWidth = 800,
    ScreenHeight = 450,
	init_window(
		ScreenWidth, 
		ScreenHeight, 
		"raylib [core] example - basic window - from Prolog!"
	),
    set_target_FPS(60),
	repeat, % This program is simple enough for a failure loop to carry all logic
	begin_drawing, 
	once(get_color(IsCrazy, BGColor)),
	clear_background(BGColor),
	draw_text("Congrats! You created your first window from Prolog!", 190, 200, 20, lightgray),
	end_drawing,
	window_should_close, 
	close_window, !.  

main_experimental :- main_experimental(not_crazy).

%having a main_loop that uses tail recursion for memory management + succeeds on window_should_close
main_loop :- begin_drawing, 
	clear_background(raywhite),
	draw_text("Congrats! You created your first window from Prolog!", 190, 200, 20, lightgray),
	end_drawing,
	window_should_close; main_loop.


main :-
	init_window(800,450,"raylib [core] example - basic window - from Prolog!"),
    set_target_FPS(60),
	main_loop, 
	close_window, !.  
