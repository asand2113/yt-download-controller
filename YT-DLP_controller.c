#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  system("clear");

  int option = -1;

  printf("Please select how to download:\n");
  printf("1) MP3\n");
  printf("2) MP4 1080p\n");
  printf("3) MP4 4K\n");
  printf("4) Update yt-dlp\n");

  scanf(" %d", &option);

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
