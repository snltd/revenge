Constant TASKS_PROVIDED;
Constant NUMBER_TASKS 20;   ! must be the size of task_scores
Constant MAX_SCORE 39;      ! must be the sum of task_scores
Constant ROOM_SCORE 1;
Constant OBJECT_SCORE 1;

! Scores for each individual task
!
Array task_scores -> 1 2 5 3 2 2 2 1 2 2 2  1  1  2  1  10 0  0  0  0;
                   ! 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19

! and what those tasks are

[	PrintTaskName index;
	switch(index) {
		0:	"escaping Christmas Eve in the pub";
		1:	"doing some rather severe pruning";
		2:	"doing some rather severe pruning and creating a skylight";
		3:	"hardening water";
		4:	"installing a downstairs skylight";
		5:	"devaluing antiques";
		6:	"doing a Keith Moon";
		7:	"making Bronson less dangerous";
		8:	"contravening the firework code";
		9:	"breaking glass";
		10:	"uncovering a secret";
		11:	"artistic dyeing";
		12:	"trimming the lightswitch";
		13:	"exploiting the conductivity band in an unsuitable location";
		14:	"lowering a roof";
		15:	"witnessing an argument";
    16: "undefined";
    17: "undefined";
    18: "undefined";
    19: "undefined";
	}
];
