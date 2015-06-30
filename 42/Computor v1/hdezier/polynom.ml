type t = (float * int) list
type solution = {
	equation: t;
	degree: int;
	nb_solutions: int;
	solution_0: float;
	solution_1: float;
}

module Parser = struct

let balance (eq0:t) (eq1:t) : t =
	let rec add_eq1_to_eq0 eq1 acc = match eq1 with
		| [] -> acc
		| (coef, degree)::next -> add_eq1_to_eq0 next (acc @ [(coef *. (-1.), degree)])
	in
	let rec degree_is_in_list lst deg = match lst with
		| [] -> false
		| (coef, degree)::next -> deg = degree || (degree_is_in_list next deg)
	in
	let rec sum_coef_of_degree lst deg acc = match lst with
		| [] -> acc
		| (coef, degree)::next when deg = degree -> sum_coef_of_degree next deg (acc +. coef)
		| (coef, degree)::next -> sum_coef_of_degree next deg acc
	in
	let rec merge_same_degree lst acc = match lst with
		| [] -> acc
		| (coef, degree)::next -> match degree_is_in_list acc degree with
			| true -> merge_same_degree next acc
			| false -> merge_same_degree next (acc @ [(sum_coef_of_degree next degree coef, degree)])
	in
	merge_same_degree (add_eq1_to_eq0 eq1 eq0) []

let to_polynom (str:string) : t =
	let split_by_add_sub (str:string) : string list =
		let rec split_by_sub lst acc = match lst with
			| [] -> acc
			| crt::next -> let adjust_sub_list = (
				let sub_list = Str.split (Str.regexp "-") crt in
				match crt.[0] = '-' with
				| true -> List.map (fun s -> "-" ^ s) sub_list
				| false -> [List.hd sub_list] @ (List.map (fun s -> "-" ^ s) (List.tl sub_list))
			)
			in
			split_by_sub next (acc @ adjust_sub_list)
		in
		split_by_sub (Str.split (Str.regexp "+") str) []
	in
	let tuple_np_of_strings (a:string) (b:string) : (float * int) =
		match Str.string_match (Str.regexp ".*X\\^.*") a 0 with
		| true when Str.string_match (Str.regexp ".*-.*") a 0 ->
			((-1.0) *. (float_of_string b), int_of_string (Str.replace_first (Str.regexp "[-X^\t]+") "" a))
		| true ->
			(float_of_string b, int_of_string (Str.replace_first (Str.regexp "[X^\t]+") "" a))
		| false when Str.string_match (Str.regexp ".*-.*") b 0 ->
			((-1.0) *. (float_of_string a), int_of_string (Str.replace_first (Str.regexp "[-X^\t]+") "" b))
		| false ->
		(float_of_string a, int_of_string (Str.replace_first (Str.regexp "[X^\t]+") "" b))
	in
	let split_by_mul (str:string) : (float * int) =
		let lst = Str.split (Str.regexp "*") str in
		match List.length lst with
			| 1 -> tuple_np_of_strings (List.hd lst) "1"
			| 2 -> tuple_np_of_strings (List.hd lst) (List.nth lst 1)
			| _ -> failwith "Too many coefficients"
	in
	let rec split_all_by_mul lst acc = match lst with
		| [] -> acc
		| crt::next -> split_all_by_mul next (acc @ [split_by_mul crt])
	in
	let remove_spaces (str:string) : string =
		Str.global_replace (Str.regexp "[ \t]+") "" str
	in
	let split_by_equal (str:string) =
		Str.split (Str.regexp "[=\t]+") str
	in
	let equations = split_by_equal str in
	(balance
	(split_all_by_mul (split_by_add_sub (remove_spaces (List.hd equations))) [])
	(split_all_by_mul (split_by_add_sub (remove_spaces (List.nth equations 1))) []))
end

module Solver = struct
	let get_nth_degree (equation:t) (n:int) =
		let rec loop_lst lst n = match lst with
			| [] -> 0.
			| (coef, degree)::_ when degree = n -> coef
			| _::next -> loop_lst next n
		in
		loop_lst equation n

	let delta (equation:t) =
		let alpha = get_nth_degree equation 2 in
		let beta = (get_nth_degree equation 1) ** 2.0 in
		let gamma = get_nth_degree equation 0 in
		print_endline ("Alpha:\t" ^ string_of_float alpha ^ "\nBeta:\t" ^ string_of_float beta ^ "\nGamma:\t" ^ string_of_float gamma);
		beta -. (4. *. alpha *. gamma)

	let make_solution (equation:t) (s0:float) (s1:float) (nb_solutions:int) =
		let max_degree eq = match List.hd eq with (coef, degree) -> degree
		in
		{
			equation = equation;
			degree = max_degree equation;
			nb_solutions = nb_solutions;
			solution_0 = s0;
			solution_1 = s1;
		}

	let unique_solution (equation:t) : float =
		let alpha = get_nth_degree equation 2 in
		let beta = (get_nth_degree equation 1) in
		(beta *. (-1.0)) /. (2.0 *. alpha)

	let double_solution (equation:t) (delta:float) : float * float =
		let alpha = get_nth_degree equation 2 in
		let beta = (get_nth_degree equation 1) ** 2.0 in
		((((-1.0) *. beta) +. (sqrt delta)) /. (2.0 *. alpha),
			(((-1.0) *. beta) -. (sqrt delta)) /. (2.0 *. alpha))

	let solve (equation:t) =
		let sort_eq = List.sort (fun (a, deg0) (b, deg1) -> deg1 - deg0) equation
		in
		let discrim = delta sort_eq
		in
		let nb_solutions (discrim:float) =
			print_endline ("Delta = " ^ string_of_float discrim);
			match discrim with
			| x when x < 0. -> 0
			| x when x = 0. && (get_nth_degree equation 2) <> 0. -> 1
			| x when x > 0. -> 2
			| _ -> (-1)
		in
		match nb_solutions discrim with
		| 0 -> make_solution sort_eq 0.0 0.0 0
		| 1 -> make_solution sort_eq (unique_solution sort_eq) 0.0 1
		| 2 -> (match double_solution sort_eq discrim with (sol0, sol1) ->
					make_solution sort_eq sol0 sol1 2)
		| _ -> failwith "No solutions"

let to_string (sol:solution) =
	let rec equation_to_string lst acc = match lst with
		| [] -> acc
		| (n, p)::[] -> acc ^ string_of_float n ^ " * X^ " ^ string_of_int p ^ " = 0"
		| (n, p)::next -> equation_to_string next (acc ^ string_of_float n ^ " * X^ " ^ string_of_int p ^ " + ")
	in
	let reduced_eq = equation_to_string sol.equation "" in
	let max_degree = "\nDegree max:\t" ^ (string_of_int sol.degree) in
	match sol.degree with
	| x when x > 0 && x < 3 ->(
		let nb_solutions = "\nNb_solutions =\t" ^ (string_of_int sol.nb_solutions) ^ "\n" in
		let solutions = match sol.nb_solutions with
			| 0 -> nb_solutions ^ "No solutions !"
			| 1 -> nb_solutions ^ "Unique solution:\t" ^ string_of_float sol.solution_0
			| 2 when (get_nth_degree sol.equation 2) = 0. -> "\nEverything is solution"
			| 2 -> nb_solutions ^ "Solution 1:\t" ^ string_of_float sol.solution_0 ^ "\nSolution 2:\t" ^ string_of_float sol.solution_1
			| _ -> "Solution solver bugged :("
		in
		reduced_eq ^ max_degree ^ solutions
	)
	| _ -> reduced_eq ^ max_degree ^ "\nDegree max must be < 3 to solve"

end
