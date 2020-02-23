
// (4)
void
InputOutput_Running_Test() {
	///////////////////// 프로그램 시작 /////////////////////////	
	// 1. 시작 정점 입력받습니다.
	// 시작 정점을 char로 입력받게 되면, enter까지 버퍼에 저장되기 때문에
	// getchar()을 사용해 \n을 삭제했습니다.	
	// 2. 먼저 Matrix_path와, DUPLICATE_ROUTE를 Array_init() 함수를 호출하여 초기화합니다.
	// Matrix_path와 DUPLICATE_ROUTE는 각각 전역변수로 선언되어 있습니다.	
	// 3. Find_Shortest_Path() 함수를 호출하여 최단 경로를 구합니다.

	char start, START;

	while (1) {
		printf(" > input the source router : ");
		scanf_s("%c", &start, 1);
		START = getchar(start != '\n');

		Array_init(Matrix_path);		Array_init(DUPLICATE_ROUTE);
		Find_Shortest_Path(start - 65);
	}
	///////////////////// 프로그램 끝 /////////////////////////
}

// (3)
void
Read_Cost(int Matrix[][PEAK_NUMBER], FILE* file) {
	//////////////////////// txt파일 변경 //////////////////////////
	// txt파일을 읽어왔습니다.
	// 현재 과제에서 읽어온 Matrix는 다음과 같습니다.
	//	0, 2, 0, 3, 0, 0, 0
	//	2, 0, 5, 0, 4, 0, 0
	//	0, 5, 0, 0, 0, 4, 3
	//	3, 0, 0, 0, 5, 0, 0
	//	0, 4, 0, 5, 0, 2, 0
	//	0, 0, 4, 0, 2, 0, 1
	//	0, 0, 3, 0, 0, 1, 0 
	// 값이 0인 부분은 정점끼리 서로 연결되지 않았습니다.
	// 계산을 편하게 하기 위해 연결되지 않은 성분은
	// 매크로 상수인 NO_CONNECTION로 바꿔줍니다.
	// 매크로 상수 NO_CONNECTION는 큰 정수값을 가지고 있습니다.

	for (int i = 0; i < PEAK_NUMBER; i++)
		for (int j = 0; j < PEAK_NUMBER; j++) {
			int r = fscanf(file, "%d ,", Matrix[i] + j);

			if (r < 1) {
				fprintf(stderr, "자료가 부족합니다.\n");
				exit(-1);
			}
			// 연결되지않은 노드의 값 변경
			if (Matrix[i][j] == 0)
				Matrix[i][j] = NO_CONNECTION;
		}
	//////////////////////// txt파일 변경 끝 //////////////////////////
}

// (2)
void
File_InputOutput() {
	///////////////////// 파일 입출력 /////////////////////////
	// txt파일을 읽어옵니다.

	FILE* fp = fopen("./Matrix_txt_6x6.txt", "r");

	if (fp == NULL) {
		puts("file open failed!!");		return -1;
	}

	Read_Cost(COST, fp);	fclose(fp);
	///////////////////// 파일 입출력 끝 /////////////////////////
}

// (1)
void
Compile_Message() {
	///////////////////// 메세지를 출력합니다 /////////////////////////
	// 메세지와 현재 정점의 갯수를 출력하며, 정점의 개수는 매크로 상수로 정의됩니다.

	printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
	printf("%%		Program to find the least-cost tree for unicast routing				%%\n");
	printf("%%					least-cost tree's vertex : %d				%%\n", PEAK_NUMBER);
	printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n");
	///////////////////// 메세지를 출력합니다 끝 /////////////////////////
}

// START
int
main() {
	///////////////////// main 함수 /////////////////////////	
	// 1. message를 출력합니다.
	// 2. txt 파일을 읽어옵니다.
	// 3. 읽어온 txt파일로 다익스트라 알고리즘을 사용하여 각각 정점에서의 경로를 구합니다.

	Compile_Message();
	File_InputOutput();
	InputOutput_Running_Test();
	///////////////////// main 함수 끝 /////////////////////////
}

