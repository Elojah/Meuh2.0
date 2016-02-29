(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Deck.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/19 15:08:28 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/19 20:59:06 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

module Card =
  struct
	module Color =
	  struct
		type t = Spade | Heart | Diamond | Club

		let all = [Spade; Heart; Diamond; Club]

		let toString t =
		  match t with
		  | Spade -> "S"
		  | Heart -> "H"
		  | Diamond -> "D"
		  | Club -> "C"
		let toStringVerbose t =
		  match t with
		  | Spade -> "Spade"
		  | Heart -> "Heart"
		  | Diamond -> "Diamond"
		  | Club -> "Club"
	  end
		
	module Value =
	  struct
		type t = T2 | T3 | T4 | T5 | T6 | T7 | T8 | T9 | T10 |
				 Jack | Queen | King | As

		let all = [T2; T3; T4; T5; T6; T7; T8; T9; T10; Jack; Queen; King; As]

		let toInt t =
		  match t with
		  | T2 -> 1
		  | T3 -> 2
		  | T4 -> 3
		  | T5 -> 4
		  | T6 -> 5
		  | T7 -> 6
		  | T8 -> 7
		  | T9 -> 8
		  | T10 -> 9
		  | Jack -> 10
		  | Queen -> 11
		  | King -> 12
		  | As -> 13

		let toString t =
		  match t with
		  | T2 -> "2"
		  | T3 -> "3"
		  | T4 -> "4"
		  | T5 -> "5"
		  | T6 -> "6"
		  | T7 -> "7"
		  | T8 -> "8"
		  | T9 -> "9"
		  | T10 -> "10"
		  | Jack -> "J"
		  | Queen -> "Q"
		  | King -> "K"
		  | As -> "A"
		let toStringVerbose t =
		  match t with
		  | Jack -> "Jack"
		  | Queen -> "Queen"
		  | King -> "King"
		  | As -> "As"
		  | _ -> toString t

		let next t =
		  match t with
		  | T2 -> T3
		  | T3 -> T4
		  | T4 -> T5
		  | T5 -> T6
		  | T6 -> T7
		  | T7 -> T8
		  | T8 -> T9
		  | T9 -> T10
		  | T10 -> Jack
		  | Jack -> Queen
		  | Queen -> King
		  | King -> As
		  | As -> invalid_arg "No next for As"
		let previous t =
		  match t with
		  | T2 -> invalid_arg "No previous for 2"
		  | T3 -> T2
		  | T4 -> T3
		  | T5 -> T4
		  | T6 -> T5
		  | T7 -> T6
		  | T8 -> T7
		  | T9 -> T8
		  | T10 -> T9
		  | Jack -> T10
		  | Queen -> Jack
		  | King -> Queen
		  | As -> King
	  end

	type t = {value: Value.t; color: Color.t;}

	let newCard value color =
	  {value = value; color;}

	let allSpades =
	  let rec inner t result =
		match t with
		| Value.As ->
		   result @ [{value = t; color = Color.Spade}]
		| t ->
		   inner (Value.next t) (result @ [{value = t; color = Color.Spade}])
	  in
	  inner Value.T2 []
	let allHearts =
	  let rec inner t result =
		match t with
		| Value.As ->
		   result @ [{value = t; color = Color.Heart}]
		| t ->
		   inner (Value.next t) (result @ [{value = t; color = Color.Heart}])
	  in
	  inner Value.T2 []
	let allDiamonds =
	  let rec inner t result =
		match t with
		| Value.As ->
		   result @ [{value = t; color = Color.Diamond}]
		| t ->
		   inner (Value.next t) (result @ [{value = t; color = Color.Diamond}])
	  in
	  inner Value.T2 []
	let allClubs =
	  let rec inner t result =
		match t with
		| Value.As ->
		   result @ [{value = t; color = Color.Club}]
		| t ->
		   inner (Value.next t) (result @ [{value = t; color = Color.Club}])
	  in
	  inner Value.T2 []
	let all =
	  allSpades @ allHearts @ allDiamonds @ allClubs
											  
	let getValue t =
	  t.value
	let getColor t =
	  t.color

	let toString t =
	  (Value.toString t.value) ^ (Color.toString t.color)
	let toStringVerbose t = 
	  "Card(" ^ (Value.toStringVerbose t.value) ^
		", " ^ (Color.toStringVerbose t.color) ^ ")"
							   
	let compare t1 t2 =
	  (Value.toInt t1.value) - (Value.toInt t2.value)						 
	let max t1 t2 =
	  if ((compare t1 t2) >= 0) then
		t1
	  else
		t2
	let min t1 t2 =
	  if ((compare t1 t2) <= 0) then
		t1
	  else
		t2

	let best t =
	  let rec inner t result =
		match t with
		| [] ->
		   result
		| head::tail ->
		   inner tail (max result head)
	  in
	  match t with
	  | [] ->
		 invalid_arg "No cards"
	  | head::tail ->
		 inner tail head

	let isOf t color =
	  t.color = color
	let isSpade t =
	  t.color = Color.Spade
	let isHeart t =
	  t.color = Color.Heart
	let isDiamond t =
	  t.color = Color.Diamond
	let isClub t =
	  t.color = Color.Club
  end

type t = (Card.t list * int)

let newDeck =
  let deck = Card.all
  in
  let shuffle d =
	let nd =
	  List.map (fun c -> (Random.bits (), c)) d
	in
	let sond =
	  List.sort compare nd
	in
	List.map snd sond
  in
  Random.self_init ();
  ((shuffle deck), 52)

let toStringList t =
  let rec inner t result =
	match t with
	| ([], _) ->
	   result
	| (head::tail, n) ->
	   inner (tail, n) (result @ [Card.toString head])
  in
  inner t []
let toStringListVerbose t =
  let rec inner t result =
	match t with
	| ([], _) ->
	   result
	| (head::tail, n) ->
	   inner (tail, n) (result @ [Card.toStringVerbose head])
  in
  inner t []

let drawCard t =
  let rec inner t =
	match t with
	| ([], _) ->
	   invalid_arg "No more cards"
	| (head::tail, n) ->
		 (head, (tail, (n - 1)))
  in
  inner t
