/**
 * editor.hh
 */

#ifndef __EDITOR_HH__
#define __EDITOR_HH__

#include <iostream>
#include <cstring>

#define BUFFER_LEN  2000


namespace editor
{
    class EditingBuffer
    {
    public:
        virtual bool replace(char c, char replacement, int offset) = 0;
        virtual int replace(std::string str, std::string replacement, int offset) = 0;
        virtual void justify(char **viewingBuffer, int rows, int cols) = 0;
        
        /**
         * Set buffer contents 
         * @param b Array of characters
         * @param len Size of b
         */
        void setBuffer(const char *b, int len) {
            memcpy(buffer, b, len < BUFFER_LEN ? len : BUFFER_LEN);
        }
        
        EditingBuffer() { memset(buffer, 0, BUFFER_LEN); }
        
    protected:
        char buffer[BUFFER_LEN];
    };
}


#endif /* __EDITOR_HH__ */ 
