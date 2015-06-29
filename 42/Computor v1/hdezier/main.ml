let exec equation =
	try
		let parsed_equation = Polynom.Parser.to_polynom equation in
		let solved_equation = Polynom.Solver.solve parsed_equation in
		print_endline (Polynom.to_string solved_equation)
	with
	| Failure e -> print_endline ("ERROR:\t" ^ e)
	| e -> print_endline ("Unrecognized error")

let () = match (Array.length (Sys.argv)) with
		| 2 -> exec Sys.argv.(1)
		| _ -> print_endline "usage: ./runner equation"
