(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   gardening.ml                                       :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/18 17:41:25 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/19 20:13:59 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type 'a tree = Nil | Node of 'a * 'a tree * 'a tree

let draw_square x y size =
  let x0 = x - size / 2
  and y0 = y - size / 2
  and x1 = x + size / 2
  and y1 = y + size / 2
  in
  Graphics.moveto x0 y0;
  Graphics.lineto x0 y1;
  Graphics.lineto x1 y1;
  Graphics.lineto x1 y0;
  Graphics.lineto x0 y0

let draw_tree node =
  let rec inner node x y n size =
	match node with
	| Nil ->
	   (
		 draw_square x y size;
		 Graphics.moveto (x - size / 3) (y - size / 3);
		 Graphics.draw_string "Nil"
	   )
	| Node(a, b, c) ->
	   (
		 draw_square x y size;
		 Graphics.moveto (x - size / 3) (y - size / 3);
		 Graphics.draw_string a;
		 (*if (b <> Nil) then*)
		   (
			 Graphics.moveto (x + size / 2) y;
			 Graphics.lineto (x + 128 - size / 2) (y + n);
			 inner b (x + 128) (y + n) (n / 2) size
		   );
		   (*if (c <> Nil) then*)
		   (
			 Graphics.moveto (x + size / 2) y;
			 Graphics.lineto (x + 128 - size / 2) (y - n);
			 inner c (x + 128) (y - n) (n / 2) size
		   )
	   )
  in
  inner node 64 384 128 42

let rec size tree =
	match tree with
	| Nil ->
	   0
	| Node(a, b, c) ->
	   1 + (size b) + (size c)

let height tree =
  let rec inner tree n =
	match tree with
	| Nil ->
	   n
	| Node(a, b, Nil) ->
	   inner b (n + 1)
	| Node(a, Nil, c) ->
	   inner c (n + 1)
	| Node(a, b, c) ->
	   max (inner b (n + 1)) (inner c (n + 1))
  in
  let n = inner tree 0
  in
  if (n > 0) then
	n - 1
  else
	0
		
let () =
  Graphics.open_graph " 1024x768";
  Graphics.set_color Graphics.black;
  let tree = Node("ALPHA",
				  Node("BETA",
					   Nil,
					   Node("DELTA", Nil, Nil)),
				  Node("GAMMA", Nil, Nil))
  in
  draw_tree tree;
  Graphics.moveto 2 2;
  Graphics.draw_string (string_of_int (size tree));
  Graphics.moveto 16 2;
  Graphics.draw_string (string_of_int (height tree));
  Graphics.moveto 66 2;
  Graphics.draw_string (string_of_int (size Nil));
  Graphics.moveto 78 2;
  Graphics.draw_string (string_of_int (height Nil));
  Graphics.read_key ();
  print_endline "Ciao"
