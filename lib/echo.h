#ifndef ECHO_H
#define ECHO_H

#define TAB_SPACE 8

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "util.h"

/**
 * @brief Echoes a string to the standard output, optionally interpreting special characters.
 *
 * This function processes an input string, potentially modifying its output based on the presence
 * of special characters and a command-line-like option "-e". If "-e" is detected at the start of
 * the input, the function will enable the interpretation of special characters.
 * The special characters can be processed by specific handling functions.
 *
 * @param value A null-terminated string that represents the input to be echoed.
 *              If the string starts with "-e ", special character processing is enabled.
 *              The function handles one special character currently: backslash (`\`).
 *              Other special characters can be added as needed.
 *
 * The function manages dynamic memory for the resulting string and ensures to free it
 * before returning. If no characters are processed into the result string, it will print
 * "(empty result)".
 *
 * @note The function modifies two global variables:
 *       - USE_SPECIAL: Indicates whether special character interpretation is enabled.
 *       - VERTICAL_TAB_COUNT: This variable is reset to 1 after the function execution.
 *
 * @example
 * char input[] = "-e Hello, World! \\n This is a test.";
 * echo(input); // Outputs: "Hello, World! \n This is a test."
 */
void echo(char value[]);
/**
 * @brief Checks if a given character is a special character.
 *
 * This function determines whether the provided character matches any of the characters
 * defined in the global array `SPECIAL_CHAR`. It iterates through the array of special
 * characters and returns true if a match is found; otherwise, it returns false.
 *
 * @param value The character to be checked.
 *
 * @return true if the character is found in the `SPECIAL_CHAR` array; false otherwise.
 *
 * @note The function relies on the global variable `SPECIAL_CHAR` and its size
 *       defined by `SPECIAL_CHAR_SIZE`. Ensure these are initialized before calling
 *       this function.
 *
 * @example
 * char c = '@';
 * if (isSpecialChar(c)) {
 *     printf("%c is a special character.\n", c);
 * } else {
 *     printf("%c is not a special character.\n", c);
 * }
 */
bool isSpecialChar(char value);
/**
 * @brief Processes a backslash command character and modifies the current string accordingly.
 *
 * This function takes a command character following a backslash (`\`) and performs
 * the corresponding action on the input string. The actions include removing whitespace,
 * adding new lines, adding horizontal tabs, or adding vertical tabs. If the command
 * character does not match any defined cases, it simply appends the character to the
 * result string.
 *
 * @param currentString A pointer to the current string being processed.
 *                      This may be modified based on the command character.
 * @param commandChar The character following the backslash (`\`) that determines
 *                    the action to be taken.
 *
 * @return A pointer to the newly constructed string after applying the command,
 *         or NULL if the operation fails.
 *
 * @note If a command character does not correspond to any specific action, the function
 *       will append the command character to the result string.
 *
 * @warning Ensure that the input string (`currentString`) is properly initialized,
 *          and remember to free any dynamically allocated memory for the result string
 *          after use to prevent memory leaks.
 *
 * @example
 * char *input = "Sample text.\\n";
 * char *output = handleBackSlashCommand(input, 'n');
 * // output will contain "Sample text.\n" after processing.
 */
char *handleBackSlashCommand(char *currentString, char commandChar);
/**
 * @brief Removes whitespace characters from the input string.
 *
 * This function takes a string and constructs a new string by omitting all
 * whitespace characters (spaces and horizontal tabs). The resulting string
 * contains only the non-whitespace characters from the original string.
 *
 * @param currentString A pointer to the input string from which whitespace
 *                      characters will be removed. This string should be null-terminated.
 *
 * @return A pointer to the newly constructed string that contains no whitespace characters,
 *         or NULL if memory allocation fails or if the input string is empty.
 *
 * @note The function uses the `expandString` function to dynamically construct the result string.
 *       Remember to free the memory allocated for the resulting string after use to avoid memory leaks.
 *
 * @example
 * char *input = "Hello, \t World! ";
 * char *output = removeWhiteSpace(input);
 * // output will contain "Hello,World!" after processing.
 */
char *removeWhiteSpace(char *currentString);
/**
 * @brief Appends a newline character to the input string.
 *
 * This function takes an input string and appends a newline character (`\n`) to it.
 * The result is a new string that contains all the characters of the original string
 * followed by the newline character.
 *
 * @param currentString A pointer to the input string to which the newline character
 *                      will be appended. This string should be null-terminated.
 *
 * @return A pointer to the newly constructed string that includes the original string
 *         followed by a newline character, or NULL if memory allocation fails.
 *
 * @note The function uses the `expandString` function to handle the dynamic memory
 *       allocation and string construction. Remember to free the memory allocated for
 *       the resulting string after use to avoid memory leaks.
 *
 * @example
 * char *input = "Hello, World!";
 * char *output = addNewLine(input);
 * // output will contain "Hello, World!\n" after processing.
 */
char *addNewLine(char *currentString);
/**
 * @brief Appends a specified number of space characters to represent a horizontal tab.
 *
 * This function takes an input string and appends a number of space characters defined
 * by the global variable `TAB_SPACE`, simulating the effect of a horizontal tab.
 * The function constructs a new string that includes the original string followed by
 * the appropriate number of spaces.
 *
 * @param currentString A pointer to the input string to which spaces will be appended.
 *                      This string should be null-terminated.
 *
 * @return A pointer to the newly constructed string that includes the original string
 *         followed by the specified number of space characters, or NULL if memory allocation fails.
 *
 * @note The function uses the `expandString` function to handle the dynamic memory
 *       allocation and string construction. Remember to free the memory allocated for
 *       the resulting string after use to avoid memory leaks.
 *
 * @example
 * char *input = "Hello, World!";
 * char *output = horizontalTabSpace(input);
 * 
 */
char *horizontalTabSpace(char *currentString);
/**
 * @brief Appends a vertical tab space to the input string.
 *
 * This function takes an input string and appends a newline character followed
 * by a specified number of space characters representing a vertical tab. The
 * number of spaces added is determined by the global variable `VERTICAL_TAB_COUNT`.
 *
 * @param currentString A pointer to the input string to which the vertical tab space
 *                      will be appended. This string should be null-terminated.
 *
 * @return A pointer to the newly constructed string that includes a newline followed
 *         by the specified number of space characters, or NULL if memory allocation fails.
 *
 * @note The function first adds a newline character using the `addNewLine` function,
 *       and then appends spaces using the `horizontalTabSpace` function. Ensure
 *       to free the memory allocated for the resulting string after use to avoid memory leaks.
 *
 * @example
 * char *input = "Hello, World!";
 * char *output = verticalTabSpace(input);
 */
char *verticalTabSpace(char *currentString);

void alertSound();


#endif // ECHO_H
