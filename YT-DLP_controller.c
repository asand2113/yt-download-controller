#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  // Checking if a list.txt exists and prompting if not
  if (access("list.txt", F_OK) == 0) {
  } else {
    fprintf(stderr, "No list.txt found.\n");
    printf("Would you like one to be created? (y/n) ");
    char selection;
    scanf("%c", &selection);
    if (selection == 'y') {
      FILE *fp = fopen("list.txt", "a");
      if (fp != NULL) {
        printf("list.txt successfully created.\n");
      } else {
        printf("Failed to create list.txt (Check file permissions).\n");
      }
      fclose(fp);
    }
    return 0;
  }

  system("clear");

  int option = -1;

  // Prompt the user
  printf("Please select how to download:\n");
  printf("1) MP3\n");
  printf("2) MP4 1080p\n");
  printf("3) MP4 4K\n");
  printf("4) Update yt-dlp\n");

  scanf(" %d", &option);

  // Check which option the user selected
  switch (option) {
  case 1:
    system("python3 yt-dlp -a list.txt -x -o '%(title)s.%(ext)s' "
           "--audio-format mp3 --audio-quality 0");
    break;
  case 2:
    system("python3 yt-dlp -a list.txt -o '%(title)s.%(ext)s' -f "
           "'bestvideo[ext!=webm][height<=1080]+bestaudio[ext!=webm]/"
           "best[ext!=webm]'");
    break;
  case 3:
    system("python3 yt-dlp -a list.txt -o '%(title)s.%(ext)s' -f "
           "'bestvideo[ext!=webm]+bestaudio[ext!=webm]/best[ext!=webm]'");
    break;
  case 4:
    system("python3 yt-dlp -U");
    break;
  default:
    break;
  }

  return 0;
}
