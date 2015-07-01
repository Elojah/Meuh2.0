type t = (float * int) list
type solution = {
	equation: t;
	degree: int;
	nb_solutions: int;
	solution_0: float;
	solution_1: float;
	im_sol_0: float * float;
	im_sol_1: float * float;
}

module Parser : sig
	val to_polynom : string -> t
end

module Solver : sig
	val solve : t -> solution
	val to_string : solution -> string
end

