(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Color.ml                                           :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/19 11:22:14 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/19 12:05:47 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type t = Spade | Heart | Diamond | Club

let all = [Spade; Heart; Diamond; Club]

let toString t =
  match t with
  | Spade ->
	 "S"
  | Heart ->
	 "H"
  | Diamond ->
	 "D"
  | Club ->
	 "C"

let toStringVerbose t =
  match t with
  | Spade ->
	 "Spade"
  | Heart ->
	 "Heart"
  | Diamond ->
	 "Diamond"
  | Club ->
	 "Club"
