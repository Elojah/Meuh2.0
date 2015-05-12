#ifndef TRIE_H
# define TRIE_H

# define MAX_CHARS_ASCII 128
# include <stddef.h>
# include <string>

class Trie
{
public:
	Trie(void);
	~Trie(void);
	Trie(Trie const &src);
	Trie&	operator=(Trie const &rhs);
	void	addValue(std::string const &value, char const *filename);
protected:
private:

	struct			sList {
		char		*value;
		sList		*next;
		void		create(char *valueSet) {
			value = valueSet;
			next = NULL;
		}
		void		addLst(char *value) {
			if (next) {
				next->addLst(value);
			} else {
				next = new sList;
				next->create(value);
			}
		}
		void		remove(void) {
			if (next != NULL) {
				next->remove();
				delete next;
			}
		}
	};

	struct			sNode {
		sNode		*children;
		sList		*files;
		void		create(void) {
			children = new sNode[MAX_CHARS_ASCII];
			files = NULL;
		}
		void		addValue(char *s, char *value) {
			int		c;

			if (!s) {
				return ;
			} else if (*s == '\0') {
				if (files) {
					files->addLst(value);
				} else {
					files = new sList;
					files->create(value);
				}
			} else if (*s >= 0) {
				c = (int)*s;
				children[c].create();
				children[c].addValue(s + 1, value);
			}
		}
		void		remove(void) {
			if (files != NULL) {
				files->remove();
				delete files;
			}
			delete[] children;
		}
	};

	sNode			_root;
};

#endif
