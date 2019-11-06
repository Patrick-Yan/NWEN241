/**
 * editor.c
 *
 * You must implement the functions in editor.h in this file.
 * Consult the assignment handout for the detailed specifications of each of the functions.
 *
 * Student ID:300476924
 * Name:YANZICHU
 */
 #include "stdio.h"
 #include "editor.h"
 #include "string.h"
 #include "stdbool.h"

 int editor_replace_str(char *editing_buffer, const char *str, const char *replacement, int offset) {
     char offsetedArray[EDITING_BUFLEN - offset];
     for (int i = 0; i + offset < EDITING_BUFLEN; i++) {
         offsetedArray[i] = editing_buffer[i + offset];
     }
     // Locates the index of the first instance of str after the offset
     if (strstr(editing_buffer, str) != NULL) {
         char *point = strstr(offsetedArray, str);
         int location = (int) ((point) - offsetedArray) + offset;
         if (strlen(str) == strlen(replacement)) {
             for (int i = 0; i < strlen(replacement); i++) {
                 editing_buffer[location + i] = replacement[i];
             }
         } else if (strlen(replacement) > strlen(str)) {
             int strLengthDifference = strlen(replacement) - strlen(str);
             int numberOfCharsToMove = EDITING_BUFLEN - location - strLengthDifference;
             if (location + strlen(replacement) > EDITING_BUFLEN) {
                 return -1;
             }
             char charsToMove[numberOfCharsToMove];
             for (int i = 0; i + location + strlen(str) < EDITING_BUFLEN; i++) {
                 charsToMove[i] = editing_buffer[i + location + strlen(str)];
             }
             for (int i = 0; i < strlen(replacement); i++) {
                 editing_buffer[i + location] = replacement[i];
             }
             for (int i = 0; i < numberOfCharsToMove; i++) {
                 if (i + location + strlen(replacement) < EDITING_BUFLEN - 1) {
                     editing_buffer[i + location + strlen(replacement)] = charsToMove[i];
                 }
             }
             if (numberOfCharsToMove + location + strlen(replacement) > EDITING_BUFLEN - 1) {
                 editing_buffer[20] = '\0';
             } else {
                 for (int i = numberOfCharsToMove + location + strlen(replacement); i < EDITING_BUFLEN; i++) {
                     editing_buffer[i] = '\0';
                 }
             }
         } else if (strlen(str) > strlen(replacement)) {
             int strLengthDifference = strlen(str) - strlen(replacement);
             int numberOfCharsToMove = EDITING_BUFLEN - location - strLengthDifference;
             char charsToMove[numberOfCharsToMove];
             for (int i = 0; i < EDITING_BUFLEN; i++) {
                 charsToMove[i] = editing_buffer[i + location + strlen(replacement) + strLengthDifference];
             }
             for (int i = 0; i < strlen(str); i++) {
                 editing_buffer[i + location] = replacement[i];
             }
             for (int i = 0; i < numberOfCharsToMove; i++) {
                 editing_buffer[i + location + strlen(replacement)] = charsToMove[i];
             }
             for (int i = location + strlen(replacement) + numberOfCharsToMove; i < EDITING_BUFLEN; i++) {
                 editing_buffer[i] = '\0';
             }
         }

     }
 }

 int editor_insert_char(char *editing_buffer, char to_insert, int pos) {
   // 1. editing_buffer is the sentence I wanna ues.
   // 2. to_insert is the char I wanna insert to the sentence.
   // 3. pos is the postion in sentence I want to insert.
     int Pos = EDITING_BUFLEN - (pos + 1);
     char toMove[Pos];
     for (int i = 0; i < Pos; i++) {
         toMove[i] = editing_buffer[i + pos];

     }
     editing_buffer[pos] = to_insert;
     for (int i = 0; i < Pos; i++) {
         editing_buffer[i + pos + 1] = toMove[i];
     }
     return 1;
 }

 int editor_delete_char(char *editing_buffer, char to_delete, int offset) {
     int deletedChar;
     for (int i = 0; i < EDITING_BUFLEN; i++) {
         if (editing_buffer[i] == to_delete) {
             deletedChar = i;
             break;
         }
     }
     if (editing_buffer[deletedChar] == to_delete) {
         for (int i = deletedChar; i < EDITING_BUFLEN - 1; i++) {
             editing_buffer[i] = editing_buffer[i + 1];
         }
         editing_buffer[EDITING_BUFLEN] = '\0';
         return 1;
     }
 }



 int main() {

     char editing_buffer[EDITING_BUFLEN] = "The quick brown fox";
     char str[] = "brown";
     char rep[] = "bro";
     int r = editor_insert_char(editing_buffer,'s', 9);
     //int r = editor_delete_char(editing_buffer,'e', 3);
     //int r = editor_replace_str(editing_buffer, str, rep, 3);
     printf("\n%s", editing_buffer);

     return 0;

 }
