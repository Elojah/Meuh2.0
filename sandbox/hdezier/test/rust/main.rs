struct Task {
}

fn read_username_from_file() -> Result<String, io::Error> {
	let mut f = File::open("test.txt")?;
	let mut s = String::new();

	f.read_to_string(&mut s)?;

	Ok(s)
	println!("{:?}", s);
}

fn main() {
	read_username_from_file();
}
