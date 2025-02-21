/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamonte <joamonte@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:12:31 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/09/12 09:01:38 by joamonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdint.h>
# include <unistd.h>
# include <stdbool.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define EPSILON 0.0001

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_buffer
{
	char	*str;
	size_t	starti;
}	t_buffer;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100

# endif

//Character check and manipulation
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
//Memory creation, search and manipulation
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
//String creation, search and manipulation
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *s);
char	*ft_strldup(const char *s, int l);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_strlinvert(char *s, int len);
//Number conversion and manipulation
bool	ft_isstr_int(char *str);
int		ft_atoi(const char *nptr);
bool	ft_isstr_float(char *str);
float	ft_atof(char *str);
char	*ft_itoa(int n);
int		ft_clamp(int n, int min, int max);
bool	ft_fcmp(float a, float b);
int		ft_pow(int i, int pow);
//Output writing
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putendl_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putnbr_base_fd(long long nbr, char *base, int fd);
int		ft_printf(const char *format, ...);
//List creation, search and manipulation
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_swap(char **a, char **b);
//Miscellaneous
int		ft_is_little_endian(void);
void	ft_matrix_free(void ***matrix);
void	**ft_matrix_dup(void **matrix);
int		ft_arr2dsize(void	**arr2d);
//Get Next Line
char	*get_next_line(int fd);
char	*merge_previous_and_current(char *previous, const char *current);
char	*cpy_buffer(const char *buffer, size_t len);
char	*find_chr(const char *buffer, int to_find);
size_t	strlen_at(const char *str, int avoid);

#endif
