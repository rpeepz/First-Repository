// fills line array with info up to \n
int      ft_afterline(char **s, char **line, int fd, int i)
{
    char            *tmp;
    int             len;

    len = 0;
    while (s[fd][len] != '\n' && s[fd][len]) // calculate index of str array
        len++;                               // where \n is found not exceeding \0
    if (s[fd][len] == '\n')  // if new line found in str array
        {
            *line = ft_strsub(s[fd], 0, len); // create return string
            tmp = ft_strdup(s[fd] + len + 1); // use tmp to store remaining info after \n
            free(s[fd]);                      // free str array
            s[fd] = tmp;                      // store tmp in str array
            if (s[fd][0] == '\0')             // delete and free pointer of str array
                ft_strdel(&s[fd]);
        }
    else if (s[fd][len] == '\0')  // if null character is found before new line
    {
        if (i == BUFF_SIZE)   // if bytes read from fd is same as buff size
            return (get_next_line(fd, line));  //no new lines have been found in the buffer
        *line = ft_strdup(s[fd]);
        ft_strdel(&s[fd]);    // delete and free pointer of str array
    }
    return (1);
}


// fills buffer from fd, stores info in str pointer array
int     get_next_line(const int fd, char **line)
{
    static char     *str[MAX_FD];
    char            *tmp;
    char            *tmp2;
    char            buf[BUFF_SIZE + 1];
    int             i;
//  int             n;

    if (fd < 0 || line == NULL || BUFF_SIZE == 0)
        return (-1);
    while (((i = read(fd, buf, BUFF_SIZE)) > 0)) 
    {                  // while there are bytes to read from fd without finding \n
        buf[i] = '\0'; // terminates buffer at end of BUFF_SIZE
        if (!str[fd])  // if no info in str array
            str[fd] = ft_strnew(0); // initialize str at fd index
        tmp = ft_strjoin(str[fd], buf); // use tmp to append buffer to str array
        free(str[fd]);                  // free str array
        str[fd] = tmp;                  // store tmp (str + buffer) in str array
        if (ft_strchr(buf, '\n'))       // if \n in buffer break from loop
            break ;
    }
/*
**    OLD CODE OBSOLETE
**    tmp = ft_strjoin(str[fd], buf);
**    *line = ft_strsub(tmp, 0, ft_strlen(str[fd]) + n);
**    tmp2 = ft_strdup(tmp + ft_strlen(str[fd]) + n + 1);
**    free(str[fd]);
**    str[fd] = tmp2;
**    *line = ft_strjoin(str[fd], ft_strsub(buf, 0, n));
**    tmp = ft_strdup(str[fd] + n);
**    free(str[fd]);
**    str[fd] = tmp;
*/
    if (i < 0)           // if negative bytes were read
        return (-1);
    else if (i == 0  && (str[fd] == NULL || str[fd][0] == '\0'))
        return (0);      // if no bytes left to read, or str aray is blank
    return (ft_afterline(str, line, fd, i)); //check for info after \n
}
