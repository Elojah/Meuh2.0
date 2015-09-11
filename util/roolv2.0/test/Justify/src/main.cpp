#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define SEP ' '
#define IS_SEP(n) ((n) == ' ')

typedef struct		s_line
{
	char			*s;
	int				n_gaps;
}					t_line;

static void		get_line_from_buffer(const char *buffer
	, unsigned int *n_buffer, int n, t_line *line)
{
	int			i;
	int			offset;
	bool		space_state = false;

	/*Clean str*/
	for (int j = 0; j < n + 1; ++j)
		line->s[j] = '\0';
	/*Superficial remove of space in line begin*/
	for (offset = 0; offset < n && IS_SEP(buffer[*n_buffer + offset]); ++offset)
		;
	line->n_gaps = 0;
	/*Line with only spaces*/
	if (offset >= n)
		return ;
	*n_buffer += offset;
	/*Actual get_line_from_buffer*/
	for (i = 0;i < n && buffer[*n_buffer + i] != '\0'; ++i)
	{
		line->s[i] = buffer[*n_buffer + i];
	/*Here we count nbr gaps*/
		if ((space_state && IS_SEP(line->s[i])) || (!space_state && !IS_SEP(line->s[i])))
			continue ;
		space_state = !space_state;
		if (!IS_SEP(line->s[i]))
			++line->n_gaps;
	}
	line->s[i] = '\0';
}

static int		spaces_to_add(int step_between_offset_spaces, int current, int *spaces_offset)
{
	if (*spaces_offset > 0
		&& (current + 1) % step_between_offset_spaces == 0)
	{
		--(*spaces_offset);
		return (1);
	}
	else
		return (0);
}

static int		ft_strncat_offset(char *dest, const t_line *orig, int n, int offset)
{
	int			spaces_offset;
	int			space_per_word;
	int			step_between_offset_spaces;
	int			j;
	int			i = 0;
	int			current_gap = 0;

	/*space_per_word is the nbr of spaces to insert between every words of the line*/
	/*spaces_offset is the nbr of insertion which take one more spaces*/
	space_per_word = offset / (orig->n_gaps);
	spaces_offset = offset - (space_per_word * orig->n_gaps);
	if (spaces_offset == 0)
		step_between_offset_spaces = 0;
	else
		step_between_offset_spaces = orig->n_gaps / spaces_offset;
	for (j = 0; j < n && orig->s[j] != '\0'; ++j)
	{
		/*Offset is handle here*/
		if (offset > 0 && j != 0 && !IS_SEP(orig->s[j]) && IS_SEP(orig->s[j - 1]))
		{
			/*spaces_to_add determine which gaps will get the bonus space*/
			for (int k = space_per_word + spaces_to_add(step_between_offset_spaces, current_gap, &spaces_offset);
				k > 0; --k)
			{
				dest[i + j] = SEP;
				++i;
			}
			++current_gap;
		}
		/*Actual strncat*/
		dest[i + j] = orig->s[j];
	}
	return (i + j);
}

static int		ft_strncat_endl(char *dest, const t_line *orig, int n, int offset)
{
	int			res;

	if (offset > 0 && orig->n_gaps > 0)
		res = ft_strncat_offset(dest, orig, n, offset);
	else
	{
		int			i = 0;
		int			j;

		for (j = 0; j < n && orig->s[j] != '\0'; ++j)
			dest[i + j] = orig->s[j];
		res = i + j;
	}
	dest[res] = '\n';
	dest[res + 1] = '\0';
	return (res + 1);
}

static int		find_last_occ(const char *buffer, int n)
{
	/*lookin for last space in dat     0  */
	/*                            ^    ^  */
	/*____________________________|____|  */
	/*                            37   42 */
	/*                            i    n  */
	for (int i = n; i >= 0; --i)
	{
		if (IS_SEP(buffer[i]))
		{
			/*ATTENTION au --i dans le define*/
			while (i > 0 && IS_SEP(buffer[--i]))
				;
			return (i + 1);
		}
	}
	return (n);
}

static void		justify(const char *orig, char *dest, unsigned int width)
{
	dest[0] = '\0';
	if (width < 1)
		return ;

	t_line				line;
	unsigned int		size = strlen(orig);
	unsigned int		n_buffer = 0;
	int					end_dest = 0;

	line.s = (char *)malloc((width + 1) * sizeof(char));
	get_line_from_buffer(orig, &n_buffer, width + 1, &line);
	while (n_buffer < size)
	{
		unsigned int		n_last_separator;

		/*To trim end of line*/
		n_last_separator = find_last_occ(line.s, width);
		/*Case 1: All words can be copied*/
		if (IS_SEP(line.s[width]))
		{
			end_dest += ft_strncat_endl(dest + end_dest, &line, n_last_separator, width - n_last_separator);
			n_buffer += width + 1;
			goto next;
		}
		/*Case 2: End of file, this is last line*/
		else if (line.s[0] != '\0' && line.s[width - 1] == '\0')
		{
			ft_strncat_endl(dest + end_dest, &line, width, 0);
			break ;
		}
		/*Case 3: Last word is cutted so we remove from this line*/
		else
		{
			--line.n_gaps;
			/*Empty line*/
			if (line.s[0] != '\0' || n_last_separator != width)
				end_dest += ft_strncat_endl(dest + end_dest, &line, n_last_separator, width - n_last_separator);
			n_buffer += n_last_separator;
		}
		next:
		get_line_from_buffer(orig, &n_buffer, width + 1, &line);
	}
	free(line.s);
}

static void		exec(void)
{
	static const char	buffer[] = "Lorem ipsum Anim sint deserunt irure ea occaecat voluptate nostrud ullamco tempor ut amet do consequat deserunt culpa id consequat sed quis Ut dolore nostrud sed magna ex non eiusmod anim Excepteur elit et laborum dolor et sit. Lorem ipsum Nostrud occaecat exercitation eu tempor non officia elit proident do ut dolore velit dolore fugiat dolor reprehenderit nisi dolore dolore aliquip amet sit velit veniam adipisicing exercitation nisi qui incididunt incididunt dolore amet ut reprehenderit fugiat cupidatat adipisicing laborum esse nisi culpa sint proident pariatur dolore ut ut deserunt mollit id in ullamco amet pariatur culpa dolore qui eiusmod et veniam deserunt nulla sunt do in pariatur officia officia quis irure laborum veniam proident officia qui eu laboris Ut exercitation exercitation dolore consectetur voluptate fugiat sit esse in in magna pariatur Ut tempor et nulla laboris deserunt nostrud dolor veniam cupidatat cillum laboris nulla adipisicing labore reprehenderit Excepteur voluptate labore amet reprehenderit eiusmod Ut officia nisi sed ullamco Duis dolore incididunt irure id cillum irure ut occaecat nostrud in laboris sint id enim labore esse Ut in id elit veniam pariatur reprehenderit eiusmod laborum elit anim ad amet voluptate sed officia fugiat incididunt ut in Excepteur dolore non Excepteur. Lorem ipsum Dolore fugiat sint nostrud nostrud ea elit mollit adipisicing ut ullamco non Excepteur ut sed sit dolore culpa aute eiusmod dolor Ut esse est exercitation est dolor non qui eiusmod dolor proident nisi dolore ea sint magna dolor voluptate anim est nulla in in qui elit commodo quis occaecat quis aliqua non velit irure occaecat elit dolore ullamco Ut ex officia tempor deserunt laborum in dolor mollit magna magna tempor laborum ullamco irure fugiat eu adipisicing laborum et mollit cillum Excepteur veniam dolor esse ea enim minim incididunt id cupidatat cillum aute ut sit dolor magna voluptate adipisicing sit deserunt cillum pariatur minim officia nulla non dolor officia labore laborum sunt aute enim laborum velit dolore eu minim est anim aliqua reprehenderit aliqua est deserunt dolore ex aute officia incididunt eu dolore ut. Lorem ipsum Excepteur voluptate do non in eu fugiat veniam consectetur dolore sint enim dolore est ut dolore ut aliquip incididunt pariatur quis laborum ut aliquip consectetur amet esse dolore laboris laborum adipisicing sunt ad incididunt Ut cupidatat amet velit laboris minim do proident consequat nostrud mollit pariatur eiusmod est ad non do do adipisicing ullamco sit in ex ad ad irure laboris laborum et et veniam culpa exercitation minim dolore nostrud consectetur non est aute cupidatat elit nostrud in in adipisicing exercitation pariatur labore voluptate eu magna est anim ullamco et consequat consectetur laborum esse aliquip adipisicing consectetur laborum minim culpa nulla dolore velit sit sit sunt do nisi quis dolor amet eu sint in nulla et sunt sed id nostrud deserunt consequat ullamco aliqua fugiat enim elit nulla sed enim pariatur labore sed adipisicing Duis in do sunt ut mollit dolor exercitation magna aliqua officia est Ut qui elit sit enim laboris qui dolor consequat quis dolore proident non occaecat deserunt cupidatat cupidatat consectetur adipisicing voluptate reprehenderit elit dolor irure dolor eiusmod sint consequat ullamco nostrud labore et ut nostrud Duis pariatur ex esse magna tempor ad aute cupidatat consequat esse ad sed fugiat voluptate qui et minim quis quis adipisicing officia ullamco deserunt elit qui veniam Excepteur est pariatur dolore labore pariatur irure in anim nostrud. Lorem ipsum Laborum in in laboris ad qui laborum irure ad qui aute aute cupidatat ex amet fugiat enim exercitation nulla mollit sint eiusmod minim occaecat esse est incididunt ex Ut Excepteur pariatur in in sint sint eiusmod Ut ut sunt proident aliqua laboris in et fugiat nostrud esse cupidatat elit in anim Ut aute officia ullamco anim dolor dolore labore in anim sint officia sint eu dolor amet deserunt consectetur elit sit et laborum occaecat officia dolor in proident irure eiusmod eu ex fugiat Ut nulla anim cupidatat sit ad exercitation velit aute laborum Excepteur sit mollit Duis esse est nisi et eu sunt velit cillum dolor adipisicing cillum esse et ut amet reprehenderit officia est velit magna labore amet non eiusmod eu reprehenderit incididunt sint et Duis irure laborum dolor id velit nisi id amet dolore anim enim dolore Ut cupidatat Duis aliqua Excepteur Ut non amet dolore nisi ea amet cillum aute cillum in id in nisi nulla amet dolor consectetur laboris aliquip proident tempor dolor ut cupidatat sed in fugiat anim ex labore laboris deserunt esse fugiat aute est sunt sed deserunt culpa do veniam cupidatat minim amet in ad irure laboris quis sunt sit occaecat adipisicing do et voluptate id ex ut irure sint deserunt labore esse ut laboris elit ad cillum Excepteur in laboris ut deserunt aliqua est mollit irure esse esse aliquip proident non consequat mollit reprehenderit nostrud enim cillum aute do minim sint esse nulla eiusmod. Lorem ipsum Et voluptate dolor irure labore sunt aliqua amet commodo quis culpa tempor consectetur dolore cillum nisi pariatur eu incididunt veniam sed adipisicing ut magna in ex exercitation sunt aute in non anim aliqua nostrud occaecat minim est fugiat nulla amet aliquip id labore anim sint occaecat sunt proident in Duis qui dolore amet consectetur pariatur dolore ea cillum sint culpa ad dolor incididunt do id consectetur in ullamco quis in cupidatat pariatur quis qui Ut veniam in id tempor esse exercitation dolore nisi officia aliqua eiusmod incididunt pariatur dolor Ut laboris ut consequat nulla sunt aliqua esse officia veniam sunt Ut dolore cupidatat dolore enim veniam veniam aliquip ea proident sint culpa laborum irure consequat labore aute adipisicing proident ad aliqua in tempor in laboris ex dolore veniam dolor adipisicing elit in in esse velit ullamco ullamco reprehenderit non velit consequat sint sit aliqua Duis labore in voluptate sed ut eiusmod magna enim eu dolor nostrud voluptate in ea non aliqua pariatur sit fugiat ea magna anim sit dolor tempor ut incididunt magna mollit officia sed veniam ut tempor exercitation nulla proident et aliqua quis consequat consequat amet magna dolor nulla do irure Ut aliqua sit non incididunt ad fugiat pariatur irure. Lorem ipsum Nisi tempor eu consectetur reprehenderit ea exercitation magna in consequat minim laborum deserunt et irure eu labore veniam culpa culpa ea amet eu sunt reprehenderit in minim tempor commodo sed et nulla occaecat adipisicing veniam ad veniam non ea non magna ex amet Duis id elit consectetur ut amet in enim reprehenderit ullamco adipisicing eu adipisicing voluptate voluptate officia est laboris in labore eu Duis Ut Excepteur culpa eiusmod in eiusmod nisi adipisicing est Ut in voluptate esse ut commodo magna eu adipisicing velit ad tempor in labore occaecat aliqua exercitation irure elit sed enim ullamco elit veniam aliqua sit consectetur aliquip cupidatat veniam nulla id ex non elit in pariatur nostrud cupidatat consectetur reprehenderit Excepteur aliquip non ad ut ex in enim cillum in ea consequat ad consectetur aliqua mollit eu dolore pariatur incididunt aute laborum et deserunt nulla laborum culpa dolore incididunt aliqua id labore est sit sit sit eiusmod nulla enim cupidatat qui pariatur ad sit nostrud sit nisi tempor dolor eu anim mollit ex nulla mollit tempor adipisicing veniam est Duis nostrud fugiat commodo nisi in. Lorem ipsum Duis consequat ad irure esse aute in exercitation eiusmod tempor magna pariatur proident laborum ullamco voluptate Duis tempor veniam in fugiat exercitation id in Ut officia cupidatat mollit Excepteur incididunt nulla nisi eiusmod fugiat Ut veniam Duis non elit laborum in adipisicing aute officia pariatur dolore sed enim enim aute pariatur sint id in enim velit ut fugiat ea enim laboris sint ut voluptate laboris do pariatur dolor aute proident et ullamco incididunt do nostrud minim et aute ut in irure ad dolore ut aute consectetur pariatur cillum reprehenderit exercitation culpa incididunt id in adipisicing id nisi aliquip dolor est elit cillum sit exercitation quis aute sunt nisi quis irure irure est veniam ea ut eiusmod proident exercitation laborum pariatur consectetur tempor voluptate ea in ut labore dolor consectetur reprehenderit laborum sint Ut id sint pariatur est ea et dolor ut commodo aliqua ut anim est deserunt dolor. Lorem ipsum Reprehenderit cillum officia culpa deserunt in sunt laboris sint in sed ea nostrud magna laborum aliqua aliquip sed occaecat nulla labore magna sed reprehenderit enim minim non qui qui officia pariatur anim amet in est eiusmod commodo proident deserunt do voluptate voluptate incididunt nostrud Duis adipisicing pariatur eiusmod qui proident consectetur pariatur pariatur consectetur officia Ut velit velit adipisicing in nulla dolore fugiat adipisicing enim laborum culpa tempor pariatur cupidatat ut proident est pariatur reprehenderit eu fugiat id eu dolor consequat culpa sunt veniam sint irure anim amet proident ullamco nostrud ad eiusmod incididunt dolore id esse ea Excepteur cillum Excepteur quis proident sed in veniam sed consectetur cillum dolor magna qui incididunt adipisicing dolore incididunt dolore veniam nulla ex labore dolor mollit Duis non sint sunt dolore tempor quis ut velit labore irure dolore dolore culpa id dolore nulla voluptate veniam id qui cillum consectetur aliqua et nisi sint minim exercitation aute officia Excepteur mollit officia irure culpa est aute ea aliquip id id esse culpa cupidatat in Duis qui labore fugiat est pariatur in in anim laboris culpa dolor in labore nostrud et sed consectetur dolore in cillum culpa nulla veniam sit elit esse exercitation culpa esse esse tempor dolore Ut nulla deserunt voluptate sed ea occaecat in sit ullamco ut qui labore dolor ut Excepteur reprehenderit amet fugiat sit dolor Excepteur dolor elit id fugiat pariatur adipisicing ullamco quis nostrud ex in. Lorem ipsum Consectetur mollit do enim mollit amet commodo et amet et labore elit esse labore esse ut ad in laborum anim aliquip veniam mollit exercitation mollit velit dolore in mollit pariatur est qui qui officia consequat occaecat culpa reprehenderit in veniam in consequat Excepteur velit eu in ut pariatur occaecat sunt elit commodo aute culpa in velit est exercitation fugiat anim sit aute et ut ut fugiat Duis qui in fugiat enim sint veniam quis labore voluptate ad exercitation qui qui eiusmod do labore labore sit elit exercitation pariatur laboris velit ullamco est incididunt magna ex dolor velit aliquip velit ut adipisicing esse ullamco mollit anim aliqua in in ea cupidatat adipisicing non quis ad deserunt eu velit consectetur ad eu cillum mollit aliquip est commodo ullamco velit irure cupidatat adipisicing enim sit dolor exercitation incididunt do sed nostrud Excepteur ea consequat est enim ex dolor do id incididunt Duis sit deserunt cupidatat dolore consectetur aliqua Excepteur ad non culpa dolor eu quis Duis veniam anim reprehenderit Duis aliqua eu incididunt mollit laborum do officia consectetur laboris sed voluptate mollit sed in cupidatat veniam officia sed cillum est do voluptate cupidatat ad laboris laborum aliquip deserunt dolor Excepteur commodo quis proident aliqua cupidatat in fugiat velit voluptate nisi laboris culpa incididunt mollit officia eu. Lorem ipsum Irure magna ex occaecat voluptate ullamco Ut sit Duis ut mollit ad reprehenderit labore labore eu enim Excepteur consequat Duis dolor Duis Duis aliquip ut irure sed veniam elit deserunt enim eiusmod occaecat commodo ullamco exercitation sunt culpa nulla adipisicing dolor quis dolor dolore enim nostrud dolor esse dolore non ex dolor nulla pariatur est sint fugiat velit proident enim velit culpa ea minim cillum enim cupidatat culpa aute officia et exercitation aute non aliquip dolor magna enim sit ea incididunt labore do eiusmod in in sunt consectetur dolor ullamco dolor non sit sunt proident cupidatat do incididunt deserunt commodo eu occaecat occaecat voluptate cupidatat anim sint fugiat aliqua Ut voluptate dolore tempor occaecat nisi incididunt Ut nisi ad magna ea eu commodo sed ea magna elit sunt non dolore dolore ad dolor nisi Duis adipisicing aute enim et reprehenderit dolore ex magna Ut amet elit Ut pariatur dolor Duis tempor pariatur dolore qui quis dolor in sed cillum laborum Excepteur eiusmod nulla adipisicing dolor do ut velit commodo incididunt deserunt eiusmod nostrud eu sunt qui mollit elit elit aliquip dolor enim laboris Ut eiusmod esse culpa aute id. Lorem ipsum Duis proident dolor in culpa pariatur sed anim dolore dolor exercitation anim mollit incididunt pariatur enim anim voluptate minim irure cillum Duis mollit minim consectetur eiusmod in ullamco laboris. Lorem ipsum Excepteur dolor labore dolor aliqua exercitation dolor proident in occaecat culpa fugiat sit laboris reprehenderit commodo nostrud. Lorem ipsum Enim aliquip ex aute anim non sed sit dolore reprehenderit ullamco eiusmod culpa qui veniam. Lorem ipsum Eu id exercitation proident magna dolore commodo eu mollit dolore velit qui amet. Lorem ipsum In dolore commodo ut enim magna voluptate sit minim incididunt qui nulla ad nisi ad do Excepteur incididunt veniam nulla aliqua proident irure consequat mollit magna sed tempor aliquip exercitation aute. Lorem ipsum Ut deserunt consequat quis dolor dolor sit magna dolor aute dolor do culpa anim consequat sit elit Excepteur voluptate dolor elit nisi labore amet consequat minim aliqua ex ex reprehenderit nisi do fugiat eu. Lorem ipsum Sit mollit laboris reprehenderit exercitation eiusmod tempor quis enim irure qui deserunt incididunt Duis fugiat qui ea aliqua Excepteur dolor fugiat adipisicing ut id. Lorem ipsum Sit reprehenderit pariatur nostrud dolor nisi cupidatat incididunt aute Excepteur et ad qui aliqua magna nostrud proident aliquip cupidatat dolore dolore culpa proident enim aliqua velit esse quis veniam proident labore et laboris sunt in culpa qui dolore incididunt do Duis aliquip laboris et voluptate consectetur commodo dolor incididunt sed enim dolore do culpa enim esse nisi enim magna sed laboris id et et minim in dolor laboris in laborum cupidatat reprehenderit amet aliquip quis ad id enim nisi non sed sint cillum Duis laboris tempor qui Excepteur amet reprehenderit cillum Ut non quis laboris culpa esse est Ut officia consequat nulla adipisicing ex Excepteur officia enim ex minim eu dolor aliquip adipisicing ut exercitation adipisicing pariatur culpa aliqua eiusmod dolor magna est dolore aliqua laborum sit aute sit dolore exercitation voluptate proident dolor ea laborum ut cupidatat laboris in qui et non dolor irure veniam incididunt labore laboris magna id nisi sint in Ut in sed pariatur dolore. Lorem ipsum Est laborum sed est cillum elit proident non fugiat veniam Excepteur id consectetur laborum dolor pariatur voluptate ut cillum proident minim anim ea mollit mollit aute nisi aliquip laboris id Ut. Lorem ipsum Elit ut qui irure dolor consequat id nulla sit ut nulla nisi eu est eiusmod dolore dolore exercitation enim consequat ullamco sunt cupidatat ad eiusmod. Lorem ipsum Eu id nisi sed anim id ea anim dolore occaecat aute ea velit dolore ex est ea laborum in non. Lorem ipsum Excepteur anim elit mollit laborum eiusmod dolore non deserunt sint cillum ut ut velit sit consequat pariatur cillum reprehenderit enim irure in Excepteur culpa et nostrud esse. Lorem ipsum Ad dolore proident ullamco consectetur nostrud ut eiusmod consectetur quis dolore Ut dolore commodo dolor ex incididunt Duis veniam nulla nisi sunt minim labore dolore mollit ut sit dolore esse aliquip dolore. Lorem ipsum Anim adipisicing veniam nisi do anim officia in eu nostrud consequat sunt dolore reprehenderit veniam deserunt nostrud nisi enim non laborum ullamco dolor qui eiusmod nulla do minim sit reprehenderit laborum.";
	char				result[30000];

	justify(buffer, result, 20);

	// printf("_____________________\n");
	// printf("%s\n", buffer);
	// printf("_____________________\n");
	printf("%s\n", result);
	// printf("_____________________\n");
}

int			main(int ac, char **av)
{
	(void)ac;
	(void)av;
	exec();
	return (0);
}
