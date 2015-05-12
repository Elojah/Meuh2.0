#ifndef FILE_SCANNER_H
# define FILE_SCANNER_H


class FileScanner
{
public:
	FileScanner(void);
	~FileScanner(void);
	FileScanner(FileScanner const &src);
	FileScanner&	operator=(FileScanner const &rhs);

	void			scan(char const *path);
	void			ask(void);
protected:
private:

	bool			isScannableFile(char const *name);
	void			scanChildren(char const *path);
	void			scanFile(char const *filename);

};

#endif
