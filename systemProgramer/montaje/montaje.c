#include <pwd.h>
#include <unistd.h> 
#include <sys/types.h>


int
main(int argc, char *argv[])
{
  struct passwd* pPassword;
  uid_t userId;
  guid_t groupId;

  userId = getuid();
  guidId = getguid();

  if (userId < 500)
    exit(1);

  pPassword = getpwuid(getuid());

  // Password = getpwuid(getuid());

  // smbmount //urania.dis/fcardona ~fcardona/mnt -o username=fcardona,uid=fcardona,gid=fcardona,rw

  
