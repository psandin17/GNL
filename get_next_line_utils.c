#include "get_next_line.h"

int	check_line_end(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n') //enquanto o buffer nao for o final da string for diferente da quebra de linha, ande com o index do mesmo
		i++;
	return (buffer[i] != '\n');	//retorna 1 caso o caractere atual nao for uma quebra de linha, caso contrario retorna zero
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)		//verificacao se a str tem valor
		return (0);
	while (str[i])	//enquanto str na posicao 0 tiver algum valor...
	{
		if (str[i] == '\n')	//se for igual a quebra de linha
			return (i + 1);	//retorna o numero de caracteres ate ela + 1('\0'), fechando assim uma string
		i++;
	}
	return (i);	//retorna exatamente o valor de i caso nao caia na condicao de ter uma quebra de linha no caminho
}

char	*get_line(char *line, char *buffer)	//line vai ser a proxima linha.
{
	char	*temp;		//delcaracao de ponteiro temporario
	int		i;			//INDEX
	int		j;			//INDEX EXTRA

	temp = line;		//temp recebe em seu endereco o valor da variavel line - para na proxima vez que rodar o prog(ou seja, buscar a next line), tenha salvo em seu conteudo qual foi a ultima linha lida
	line = malloc(sizeof(char) * ft_strlen(buffer) + ft_strlen(line) + 1);	//line aloca memoria referente ao tamanho da variavel estatica e a normal + 1('\0')
	if (!line)			//verificacao do malloc
		return (NULL);
	i = 0;	//atribuicao de index
	j = 0;	//atribuicao de index
	while (temp && temp[i])	//caso temp tenha valor
	{
		line[i] = temp[i];	//line recebe seu valor
		i++;	//e o index vai andando ate o nulo
	}
	while (buffer[j])	//enquanto a variavel estatitica em zero tiver valor
	{
		line[i++] = buffer[j];	//line recebe o seu valor
		if (buffer[j++] == '\n')	//se for igual a quebra de linha, break na funcao, caso contrario...
			break ;
	}
	line[i] = '\0';	//... atribui-se o '\0' no final da string
	if (temp)	//se tiver algum valor na temporaria..
		free(temp);	//desaloque a memoria
	return (line);	//e retorne a linha adquirida
}

void	ft_clean_buff(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (buffer[i])	//enquanto o buffer tiver valor atribuido
	{
		if (j == -1 && buffer[i] == '\n')	//se o valor de j for -1(ja foi atribuido anteriormente) e o buffer no index 0 for a quebra de linha...
			j = 0;		//j = 0;
		else if (j >= 0) //caso a funcao tenha caido na condicao de cima
			buffer[j++] = buffer[i];	//Se sim, copia o caractere atual para a posição j e incrementa j
		buffer[i++] = 0;	// Limpa o caractere atual em buffer[i] (atribui 0).
	}
}
