#ifndef _JSON_PARSER_H_
#define _JSON_PARSER_H_

#ifdef __cplusplus
extern "C" {
#endif
 
/**
 * JSON type identifier. Basic types are:
 *  o Object
 *  o Array
 *  o String
 *  o Other primitive: number, boolean (true/false) or null
 */
typedef enum {
    JSMN_UNDEFINED = 0,
    JSMN_OBJECT = 1,
    JSMN_ARRAY = 2,
    JSMN_STRING = 3,
    JSMN_PRIMITIVE = 4
} jsmntype_t;

enum jsmnerr {
    /* Not enough tokens were provided */
    JSMN_ERROR_NOMEM = -1,
    /* Invalid character inside JSON string */
    JSMN_ERROR_INVAL = -2,
    /* The string is not a full JSON packet, more bytes expected */
    JSMN_ERROR_PART = -3
};


/**
 * JSON token description.
 * type     type (object, array, string etc.)
 * start    start position in JSON data string
 * end      end position in JSON data string
 */
typedef struct {
    jsmntype_t type;
    int start;
    int end;
    int size;
#ifdef JSMN_PARENT_LINKS
    int parent;
#endif
} jsmntok_t;

/**
 * JSON parser. Contains an array of token blocks available. Also stores
 * the string being parsed now and current position in that string
 */
typedef struct {
    unsigned int pos; /* offset in the JSON string */
    unsigned int toknext; /* next token to allocate */
    int toksuper; /* superior token node, e.g parent object or array */
} jsmn_parser_t;


class jsmnClass{
private :

    jsmntok_t* allocToken(jsmn_parser_t *tokenParser, jsmntok_t *tokens, size_t num_tokens);
    void fillToken(jsmntok_t *token, jsmntype_t type, int start, int end);
    int parsePrimitive(jsmn_parser_t *tokenParser, const char *js, size_t len, jsmntok_t *tokens, size_t num_tokens);
    

public:
    void Init(jsmn_parser_t *tokenParser);
    int equate(const char *json, jsmntok_t *tok, const char *s);
    int parse(jsmn_parser_t *tokenParser, const char *js, size_t len, jsmntok_t *tokens, unsigned int num_tokens);
    int parseString(jsmn_parser_t *tokenParser, const char *js, size_t len, jsmntok_t *tokens, size_t num_tokens);

};

extern jsmnClass jsmn;

#ifdef __cplusplus
}
#endif

#endif
