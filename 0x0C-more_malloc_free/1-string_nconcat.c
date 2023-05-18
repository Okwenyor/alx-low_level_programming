#include <stdlib.h>

char *string_nconcat(const char *s1, const char *s2, unsigned int n) {
    char *concatenated;
    unsigned int len1 = 0, len2 = 0, concatLen, i, j;

    /* Check if s1 is NULL and treat it as an empty string */
    if (s1 == NULL)
        s1 = "";

    /* Calculate the lengths of s1 and s2 */
    while (s1[len1] != '\0')
        len1++;
    while (s2[len2] != '\0')
        len2++;

    /* Set the actual number of bytes to copy from s2 */
    if (n >= len2)
        n = len2;

    /* Calculate the length of the concatenated string */
    concatLen = len1 + n;

    /* Allocate memory for the concatenated string */
    concatenated = (char *)malloc((concatLen + 1) * sizeof(char));

    /* Check if memory allocation was successful */
    if (concatenated == NULL)
        return NULL;

    /* Copy s1 into the concatenated string */
    for (i = 0; i < len1; i++)
        concatenated[i] = s1[i];

    /* Copy the first n bytes of s2 into the concatenated string */
    for (j = 0; j < n; j++)
        concatenated[i++] = s2[j];

    /* Add null terminator at the end */
    concatenated[i] = '\0';

    return concatenated;
}

