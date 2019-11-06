/**
 * editor.h
 */

#ifndef __EDITOR_H__
#define __EDITOR_H__

#define EDITING_BUFLEN  2000
#define VIEWING_COLS    80
#define VIEWING_ROWS    25

int editor_insert_char(char *editing_buffer, char to_insert, int pos);

int editor_delete_char(char *editing_buffer, char to_delete, int offset);

int editor_replace_str(char *editing_buffer, const char *str, const char *replacement, int offset);

void editor_view(char **viewing_buffer, const char *editing_buffer, int wrap);


#endif /* __EDITOR_H__ */ 
