(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ex03.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/23 15:02:46 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/23 17:33:23 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

module type FIXED =
	sig
		type t
		val of_float : float -> t
		val of_int : int -> t
		val to_float : t -> float
		val to_int : t -> int
		val to_string : t -> string
		val zero: t
		val one: t
		val succ: t -> t
		val pred: t -> t
		val min: t -> t -> t
		val max: t -> t -> t
		val gth: t -> t -> bool
		val lth: t -> t -> bool
		val gte: t -> t -> bool
		val lte: t -> t -> bool
		val eqp: t -> t -> bool
		val eqs: t -> t -> bool
		val add: t -> t -> t
		val sub: t -> t -> t
		val mul: t -> t -> t
		val div: t -> t -> t
		val foreach: t -> t -> (t -> unit) -> unit
	end

module type FRACTIONNAL_BITS =
	sig
		val bits: int
	end

module type MAKE =
	functor (FractionnalBits: FRACTIONNAL_BITS) -> FIXED
		
module Make: MAKE =
	functor (FractionnalBits: FRACTIONNAL_BITS) ->
					struct
						type t = {raw: int; bits: int}
						let of_float x =
							{
								raw = int_of_float
											 (x *. (float_of_int (1 lsl FractionnalBits.bits)));
								bits = FractionnalBits.bits;
							}
						let of_int x =
							{
								raw = x lsl FractionnalBits.bits;
								bits = FractionnalBits.bits;
							}							
						let to_float t =
							(float_of_int t.raw) /. (float_of_int (1 lsl t.bits))
						let to_int t =
							t.raw lsr t.bits
						let to_string t =
							string_of_float (to_float t)
						let zero = {raw = 0; bits = FractionnalBits.bits}
						let one = of_int 1
						let succ t = {raw = (t.raw + 1); bits = t.bits}
						let pred t = {raw = (t.raw - 1); bits = t.bits}
						let min t1 t2 =
							if (t1 .raw <= t2.raw) then
								t1
							else
								t2
						let max t1 t2 =
							if (t1 .raw >= t2.raw) then
								t1
							else
								t2
						let gth t1 t2 = t1.raw > t2.raw
						let lth t1 t2 = t1.raw < t2.raw
						let gte t1 t2 = t1.raw >= t2.raw
						let lte t1 t2 = t1.raw <= t2.raw
						let gth t1 t2 = t1.raw > t2.raw
						let eqp t1 t2 = t1 == t2
						let eqs t1 t2 =
							t1.raw = t2.raw
						let add t1 t2 =
							{
								raw = (t1.raw + t2.raw);
								bits = FractionnalBits.bits;
							}
						let sub t1 t2 =
							{
								raw = (t1.raw - t2.raw);
								bits = FractionnalBits.bits;
							}
						let mul t1 t2 =
							let btmp = FractionnalBits.bits in
							let rtmp = t1.raw * t2.raw in
							{
								raw = (rtmp + (rtmp land 1 lsl (btmp - 1) lsl 1)) lsr btmp;
								bits = btmp;
							}
						let div t1 t2 =
							if (t2.raw = 0) then
								invalid_arg "Can't divide by 0";
							let btmp = FractionnalBits.bits in
							{
								raw = (t1.raw lsl btmp) / t2.raw;
								bits = btmp;
							}
						let foreach t1 t2 f =
							let rec inner t1 t2 =
								if (eqs t1 t2) then
									f t1
								else
									(
										f t1;
										inner (succ t1) t2
									)
							in
							inner t1 t2
					end

module Fixed4: FIXED = Make (struct let bits = 4 end)
module Fixed8: FIXED = Make (struct let bits = 8 end)

let () =
	let x8 = Fixed8.of_float 21.10 in
	let x4 = Fixed4.of_float 21.10 in
	let y8 = Fixed8.of_float 21.32 in
	let y4 = Fixed4.of_float 21.32 in
	let r8 = Fixed8.add x8 y8 in
	print_endline (Fixed8.to_string r8);
	Fixed4.foreach (Fixed4.zero) (Fixed4.one)
								 (fun f -> print_endline (Fixed4.to_string f));
	Fixed8.foreach (Fixed8.zero) (Fixed8.one)
								 (fun f -> print_endline (Fixed8.to_string f));
	print_endline (Fixed8.to_string (Fixed8.mul x8 y8));
	print_endline (Fixed4.to_string (Fixed4.mul x4 y4));
	print_endline (Fixed8.to_string (Fixed8.div x8 y8));
	print_endline (Fixed8.to_string (Fixed8.sub x8 y8));
	print_endline (Fixed8.to_string (Fixed8.pred x8));
	if (Fixed8.gth x8 y8) then
		print_endline "Fixed8.gth x8 y8: true"
	else
		print_endline "Fixed8.gth x8 y8: false";
	if (Fixed8.lth x8 y8) then
		print_endline "Fixed8.lth x8 y8: true"
	else
		print_endline "Fixed8.lth x8 y8: false";
	if (Fixed8.lte x8 x8) then
		print_endline "Fixed8.lte x8 x8: true"
	else
		print_endline "Fixed8.lte x8 x8: false";
	if (Fixed8.gte x8 x8) then
		print_endline "Fixed8.gte x8 x8: true"
	else
		print_endline "Fixed8.gte x8 x8: false";
	if (Fixed8.eqs x8 y8) then
		print_endline "Fixed8.eqs x8 y8: true"
	else
		print_endline "Fixed8.eqs x8 y8: false";
	let w8 = Fixed8.sub x8 y8 in
	print_endline (Fixed8.to_string w8);
	print_endline (Fixed8.to_string Fixed8.one);
	print_endline (Fixed8.to_string (Fixed8.add x8 w8));
	let z8 = x8 in
	if (Fixed8.eqs x8 z8) then
		print_endline "Fixed8.eqs x8 z8: true"
	else
		print_endline "Fixed8.eqs x8 z8: false";
	print_endline (Fixed8.to_string (Fixed8.min (Fixed8.max x8 y8) w8));
	print_endline (Fixed8.to_string (Fixed8.max (Fixed8.min x8 y8) w8));
	if (Fixed8.eqp x8 x8) then
		print_endline "Fixed8.eqp x8 x8: true"
	else
		print_endline "Fixed8.eqp x8 x8: false";
	try
		print_endline (Fixed8.to_string (Fixed8.div x8 Fixed8.zero))
	with Invalid_argument e ->
		print_endline e;
