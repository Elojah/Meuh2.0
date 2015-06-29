type t = (float * int) list

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
	let separate_by_add (str:string) : string list =
		Str.split (Str.regexp "[+\t]+") str
	in
	let tuple_np_of_strings (a:string) (b:string) : (float * int) =
		match Str.string_match (Str.regexp "[X^*\t]+") a 0 with
		| true -> (float_of_string b, int_of_string (Str.replace_first (Str.regexp "[X^\t]+") "" a))
		| _ -> (float_of_string a, int_of_string (Str.replace_first (Str.regexp "[X^\t]+") "" b))
	in
	let separate_by_mul (str:string) : (float * int) =
		let lst = Str.split (Str.regexp "[*\t]+") str in
		match List.length lst with
			| 1 -> tuple_np_of_strings (List.hd lst) "0"
			| 2 -> tuple_np_of_strings (List.hd lst) (List.nth lst 1)
			| _ -> failwith "Too many coefficients"
	in
	let rec separate_all_by_mul lst acc = match lst with
		| [] -> acc
		| crt::next -> separate_all_by_mul next (acc @ [separate_by_mul crt])
	in
	let remove_spaces (str:string) : string =
		Str.global_replace (Str.regexp "[ \t]+") "" str
	in
	let separate_by_equal (str:string) =
		Str.split (Str.regexp "[=\t]+") str
	in
	let equations = separate_by_equal str in
	(balance
	(separate_all_by_mul (separate_by_add (remove_spaces (List.hd equations))) [])
	(separate_all_by_mul (separate_by_add (remove_spaces (List.nth equations 1))) []))
end

module Solver = struct
	type solution = {
		equation: t;
		degree: int;
		nb_solutions: int;
		solution_0: float;
		solution_1: float;
	}

	let solve (equation:t) = {
		equation = equation;
		degree = 1;
		nb_solutions = 0;
		solution_0 = 0.0;
		solution_1 = 0.0;
	}
end

let to_string (sol:Solver.solution) =
	let rec equation_to_string lst acc = match lst with
		| [] -> acc
		| (n, p)::next -> equation_to_string next (acc ^ string_of_float n ^ " * X^ " ^ string_of_int p ^ " + ")
	in
	equation_to_string sol.equation ""
