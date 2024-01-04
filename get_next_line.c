
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];		//declaracao variavel estatica, com o numero de caracteres o mesmo do buffer size, ja que char = 1 byte
	char		*line;						//declaracao de ponteiro que sera a proxima linha (string)
	int			i;							//declaracao do index
	int			docsize;					//declaracao do docsize(tamanho do documento)

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)		//verificacao, caso o fd seja menor que zero(impossivel), buffer size <= 0 ou menor, ou read de 0 bytes
		return (0);												// a funcao deve retornar 0
	line = NULL;				//atribuicao de valor a linha.
	i = 1;					//i = 1, para caso passe da verificacao acima, conseguir entrar no while abaixo
	while (i)				// enquanto i tiver valor...
	{
		docsize = 1;		//o peso do doc deve ser no minimo 1
		if (!buffer[0])		//caso o buffer na posicao zero nao tiver valor
			docsize = read(fd, buffer, BUFFER_SIZE);		//docsize = o retorno da funcao read(bytes lidos)
		i = (check_line_end(buffer) && docsize > 0);	//i = o fim da linha (ate o '\n') caso o doc size > 0
		if (docsize > 0)		//se o doc size > 0
			line = get_line(line, buffer);	//line = valor da proxima linha adquirido atraves da funcao get line
		ft_clean_buff(buffer);		//chama a funcao clean para limpar o buffer.
	}
	return (line);
}
