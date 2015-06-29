type t = (int * int) list

module Parser : sig
	val to_polynom : string -> t
end

module Solver : sig
	type solution = {
		equation: t;
		degree: int;
		nb_solutions: int;
		solution_0: float;
		solution_1: float;
	}

	val solve : t -> solution
end

val to_string : Solver.solution -> string
