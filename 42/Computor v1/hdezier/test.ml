let test_reg s =
	Str.global_replace (Str.regexp "[ \t]+") "" s

let () = print_endline (test_reg "   oiodsf sd f ds fds fd   =sd =fds ")
