#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char *auth = NULL;
char *service = NULL;

int main(void)
{
  char buf[128];

  do
  {
    printf("%p, %p \n", auth, service);
    if (!fgets(buf, 128, stdin))
      break;

    // This is a pseudocode
    if (strncmp(buf, "auth ", 5) == 0)
    {
      auth = (char *)malloc(4);
      char *name = (buf + 5);

      if (strlen(name) < 31)
        strcpy(auth, name);
    }
    else if (strncmp(buf, "reset", 5) == 0)
    {
      if (auth)
        free(auth);
    }
    else if (strncmp(buf, "service", 7) == 0)
    {
        service = strdup(buf + 7);
    }
    else if (strncmp(buf, "login", 5) == 0)
    {
      if ((&auth + 32) == &service)
        system("/bin/sh");
      else
        fwrite("Password:\n", 1, 10, stdout);
    }
  } while (true);
  return 0;
}
