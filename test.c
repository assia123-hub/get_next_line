char	*extract_line(char **stored)
{	
	char	*newline; // hna khassna n7etto l'adresse dial '\n' li l9ina f stored
	char	*line;  // hna ghadi nkhazno dakchi li qbel '\n' f wa7d string
	char	*lba9i;  // hna nkhazno dakchi li baqi mn ba3d '\n' f stored
	size_t	toul_line;  // hna kanhsbo toule dial dakchi li qbel '\n' bach nallociw liha

	newline = ft_strchr(*stored, '\n'); // hna kanqalbo f stored ela '\n' wkhassna n7etto l'adresse dialha f newline
	if (!newline)  // ila malqina '\n', ma kaynach line fa nraj3o NULL
		return (NULL);
	toul_line = newline - *stored + 1; // hna kanhsbo toule dial dakchi li qbel '\n' (+1 bach ndzido '\n' f line)
	line = (char *)malloc(toul_line + 1); // kanallocew memory dial string (toul_line + '\0')
	if (!line)   // ila malloc mat7ellatch, nraj3o NULL
		return (NULL);
	ft_strlcpy(line, *stored, toul_line + 1); // kan9elbo dakchi li qbel '\n' mn stored wkan7etouh f line
	if (*(newline + 1) != '\0') // ila ba9i 7aja mn ba3d '\n' f stored
	{
		lba9i = ft_strdup(newline + 1); // kan9edro lba9i dial stored mn ba3d '\n'
		free(*stored); // kanfreew memory li kan fiha stored
		*stored = lba9i; // kan3awdo nassigniw ba9i stored
	}
	else // ila makanch ba9i 7aja mn ba3d '\n'
	{
		free(*stored); // kanfreew memory dial stored
		*stored = NULL; // kanassigniw NULL bach n9t3o ta3li9ha
	}
	return (line); // kanraj3o line
}


char	*get_next_line(int fd) // hadi fonction li katqra lina file line b line
{
	static char	*stored = NULL; // static var bach takhzan dakchi li qrinah wma tmchich mn wa7d call l'autre
	char		*buffer; // buffer bach n9raw mn file
	char		*line; // line li ghadi nraj3o
	ssize_t		read_bytes; // hadchi bach nkhzanou 3adad bytes li qrinah
	char		*temp; // variable temporaire bach nakhdmo bih

	if (fd < 0 || BUFFER_SIZE <= 0) // ila fd negatif wla BUFFER_SIZE <= 0, nraj3o NULL
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1); // kanallocew memory dial buffer bach nqraw BUFFER_SIZE bytes
	if (!buffer) // ila malloc mat7ellatch
		return (NULL);
	while ((read_bytes = read(fd, buffer, BUFFER_SIZE)) > 0) // kanqrawo mn fd BUFFER_SIZE bytes, n7tohom f buffer
	{
		buffer[read_bytes] = '\0'; // kanzido '\0' bach n3tabrou buffer string
		if (!stored) // ila stored khawi
			stored = ft_strdup(""); // kanassigniw string khawi
		temp = ft_strjoin(stored, buffer); // kanmerge stored m3a buffer
		free(stored); // kanfreew stored l9dima
		stored = temp; // kanassigniw temp l stored
		if (ft_strchr(stored, '\n')) // ila l9ina '\n' f stored
		{
			line = extract_line(&stored); // kanextractiw line mn stored
			free(buffer); // kanfreew buffer bach n7aydo memory dialo
			return (line); // nraj3o line
		}
	}
	free(buffer); // ila ma l9ina '\n', kanfreew buffer
	if (stored && *stored != '\0') // ila ba9i chi 7aja f stored
	{
		line = ft_strdup(stored); // kan9elb stored wkanassigniw f line
		free(stored); // kanfreew stored
		stored = NULL; // kanassigniwha NULL
		return (line); // nraj3o line
	}
	return (NULL); // ila ma ba9atch hta haja nraj3o NULL
}
