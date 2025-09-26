#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_dict
{
    unsigned long long number;
    char *word;
    struct s_dict *next;
} t_dict;

int is_space(char c);
int is_digit(char c);
unsigned long long ft_atoi(char *str);
char *ft_strdup(char *str);

t_dict *create_node(unsigned long long num, char *word)
{
    t_dict *new_node = malloc(sizeof(t_dict));
    if (!new_node)
        return NULL;

    new_node->number = num;
    new_node->word = word;
    new_node->next = NULL;
    return new_node;
}

void add_node(t_dict **dict, t_dict *new_node)
{
    if (!*dict)
    {
        *dict = new_node;
    }
    else
    {
        t_dict *current = *dict;
        while (current->next)
            current = current->next;
        current->next = new_node;
    }
}

void free_dict(t_dict *dict)
{
    t_dict *temp;
    while (dict)
    {
        temp = dict;
        dict = dict->next;
        free(temp->word);
        free(temp);
    }
}

char *find_in_dict(t_dict *dict, unsigned long long n)
{
    t_dict *current = dict;
    while (current)
    {
        if (current->number == n)
            return current->word;
        current = current->next;
    }
    return NULL;
}

t_dict *load_dict(char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
        return NULL;

    t_dict *dict = NULL;
    char buffer[1024];
    int bytes_read;

    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
    {
        int idx = 0;
        while (idx < bytes_read)
        {
            char line[256];
            int line_idx = 0;

            while (idx < bytes_read && buffer[idx] != '\n')
            {
                line[line_idx++] = buffer[idx++];
            }
            line[line_idx] = '\0';
            if (idx < bytes_read)
                idx++;

            if (line_idx > 0)
            {
                int num_start = 0;
                int num_end = 0;
                int word_start = 0;
                int word_end = 0;
                int colon_pos = -1;
                int j = 0;

                while (j < line_idx)
                {
                    if (line[j] == ':')
                    {
                        colon_pos = j;
                        break;
                    }
                    j++;
                }

                if (colon_pos == -1)
                    continue;

                j = 0;
                while (j < colon_pos && is_space(line[j]))
                    j++;

                num_start = j;
                while (j < colon_pos && is_digit(line[j]))
                    j++;
                num_end = j;

                j = colon_pos + 1;
                while (j < line_idx && is_space(line[j]))
                    j++;

                word_start = j;
                word_end = line_idx;
                while (word_end > word_start && is_space(line[word_end - 1]))
                    word_end--;

                if (num_start < num_end && word_start < word_end)
                {
                    char num_str[64];
                    char word_str[256];
                    int k = 0;

                    j = num_start;
                    while (j < num_end)
                    {
                        num_str[k++] = line[j++];
                    }
                    num_str[k] = '\0';

                    k = 0;
                    j = word_start;
                    while (j < word_end)
                    {
                        word_str[k++] = line[j++];
                    }
                    word_str[k] = '\0';

                    unsigned long long num = ft_atoi(num_str);
                    char *word_copy = ft_strdup(word_str);
                    t_dict *new_node = create_node(num, word_copy);
                    add_node(&dict, new_node);
                }
            }
        }
    }

    close(fd);
    return dict;
}