
:- ['raylib55.pro'].

:- discontiguous(draw_state/1).
:- discontiguous(update_state/2).

draw_state(logo(_)) :- clear_background(raywhite),
	draw_text("LOGO SCREEN - from Prolog!", 20, 20, 40, lightgray),
	draw_text("WAIT for 2 SECONDS...", 290, 220, 20, gray).
	
update_state(logo(N), logo(Np1)) :- N < 120, Np1 is N + 1.
update_state(logo(120), title).

draw_state(title) :- clear_background(green),
	draw_text("TITLE SCREEN - from Prolog!", 20, 20, 40, darkgreen),
	draw_text("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, darkgreen).

update_state(title, game(0, 1)) :- is_key_pressed(key_enter).
update_state(title, title) :- \+is_key_pressed(key_enter).

draw_state(game(T0, T1)) :- clear_background(purple),
	draw_text("GAMEPLAY SCREEN - from Prolog!", 20, 20, 40, maroon),
	draw_text("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, maroon),
	FPS is round(1 / (T1 - T0)), number_string(FPS, FPS_string), 
	string_concat("FPS = ", FPS_string, FPS_display),
	draw_text(FPS_display, 160, 280, 20, yellow).

update_state(game(_, _), endscreen) :- is_key_pressed(key_enter).
update_state(game(_, T1), game(T1, T2)) :- \+is_key_pressed(key_enter), get_time(T2).

draw_state(endscreen) :- clear_background(blue),
	draw_text("ENDING SCREEN - from Prolog!", 20, 20, 40, darkblue),
	draw_text("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, darkblue).

update_state(endscreen, title) :- is_key_pressed(key_enter).
update_state(endscreen, endscreen) :- \+is_key_pressed(key_enter).

%having a main_loop that uses tail recursion for memory management + succeeds on window_should_close
main_loop(State) :- begin_drawing, 
	draw_state(State),
	end_drawing,
	update_state(State, NextState),
	(window_should_close; main_loop(NextState)).

main_loop :- main_loop(logo(0)).

main :-
	init_window(800,450,"raylib [core] example - basic screen manager - from Prolog!"),
    set_target_FPS(60),
	main_loop, 
	close_window, !.  

