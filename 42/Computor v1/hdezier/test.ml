let test_reg s =
	Str.string_match (Str.regexp ".*X\\^") s 0


let () = if (test_reg "-X^") then print_endline "OK" else
	print_endline "None"
