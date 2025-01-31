#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int binarySearch(int array[], int target, int min, int max){
  if(min > max){ return -1; }
  int pointer = (min+max)/2;
  
  if(target == array[pointer]){ 
    return pointer; 
  } 
  
  if(target > array[pointer] ){
    return binarySearch(array, target, pointer+1, max);
  } else {
    return binarySearch(array, target, min, pointer-1);
  }
}

void main(){
  int array[] = {
    2, 4, 7, 10, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48, 51, 54, 57,
    60, 63, 66, 69, 72, 75, 78, 81, 84, 87, 90, 93, 96, 99, 102, 105, 108, 111, 114, 117,
    120, 123, 126, 129, 132, 135, 138, 141, 144, 147, 150, 153, 156, 159, 162, 165, 168, 171,
    174, 177, 180, 183, 186, 189, 192, 195, 198, 201, 204, 207, 210, 213, 216, 219, 222, 225,
    228, 231, 234, 237, 240, 243, 246, 249, 252, 255, 258, 261, 264, 267, 270, 273, 276, 279,
    282, 285, 288, 291, 294, 297, 300, 303, 306, 309, 312, 315, 318, 321, 324, 327, 330, 333,
    336, 339, 342, 345, 348, 351, 354, 357, 360, 363, 366, 369, 372, 375, 378, 381, 384, 387,
    390, 393, 396, 399, 402, 405, 408, 411, 414, 417, 420, 423, 426, 429, 432, 435, 438, 441,
    444, 447, 450, 453, 456, 459, 462, 465, 468, 471, 474, 477, 480, 483, 486, 489, 492, 495,
    498, 501, 504, 507, 510, 513, 516, 519, 522, 525, 528, 531, 534, 537, 540, 543, 546, 549,
    552, 555, 558, 561, 564, 567, 570, 573, 576, 579, 582, 585, 588, 591, 594, 597, 600, 603,
    606, 609, 612, 615, 618, 621, 624, 627, 630, 633, 636, 639, 642, 645, 648, 651, 654, 657,
    660, 663, 666, 669, 672, 675, 678, 681, 684, 687, 690, 693, 696, 699, 702, 705, 708, 711,
    714, 717, 720, 723, 726, 729, 732, 735, 738, 741, 744, 747, 750, 753, 756, 759, 762, 765,
  };
  int arrayLength = sizeof(array)/sizeof(array[0]);

  srand(time(0));
  int targetIndex = rand()%(arrayLength+2);
  printf("Target index: %d\n", targetIndex);
  printf("Target: %d\n", array[targetIndex]);

  int ans = binarySearch(array, array[targetIndex], 0, arrayLength);
  printf("Ans Index: %d\n", ans);
}