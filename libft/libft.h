#include <unistd.h>
#include <stdlib.h>

// Function Prototypes Only

// ft_isalpha

int		ft_isalpha(int c);

// ft_isdigit

int		ft_isdigit(int c);

// ft_isalnum

int		ft_isalnum(int c);

// ft_isascii

int		ft_isascii(int c);

// ft_isprint

int		ft_isprint(int c);

// ft_strlen

size_t	ft_strlen(const char *s);

// ft_memset

void	*ft_memset(void *b, int c, size_t len);

// ft_bzero

void	ft_bzero(void *s, size_t n);

// ft_memcpy

void	*ft_memcpy(void *dst, const void *src, size_t n);

// ft_memmove

void	*ft_memmove(void *dst, const void *src, size_t len);

// ft_strlcpy

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

// ft_strlcat

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

// ft_toupper

int		ft_toupper(int c);

// ft_tolower

int		ft_tolower(int c);

// ft_strchr

char	*ft_strchr(const char *s, int c);

// ft_strrchr

char	*ft_strrchr(const char *s, int c);

// ft_strncmp

int		ft_strncmp(const char *s1, const char *s2, size_t n);

// ft_memchr

void	*ft_memchr(const void *s, int c, size_t n);

// ft_memcmp

int		ft_memcmp(const void *s1, const void *s2, size_t n);

// ft_strnstr

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

// ft_atoi

int		ft_atoi(const char *str);

// ft_calloc

void	*ft_calloc(size_t nmemb, size_t size);

// ft_strdup

char	*ft_strdup(const char *s);

// ft_substr

char	*ft_substr(const char *s, unsigned int start, size_t len);

// ft_strjoin

char	*ft_strjoin(const char *s1, const char *s2);

// ft_strtrim

char	*ft_strtrim(const char *s1, const char *set);

// ft_split

char	**ft_split(const char *s, char c);

// ft_itoa

char	*ft_itoa(int n);

// ft_strmapi

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));

// ft_striteri

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// ft_putchar_fd

void	ft_putchar_fd(char c, int fd);

// ft_putstr_fd

void	ft_putstr_fd(const char *s, int fd);

// ft_putendl_fd

void	ft_putendl_fd(const char *s, int fd);

// ft_putnbr_fd

void	ft_putnbr_fd(int n, int fd);