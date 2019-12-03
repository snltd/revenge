Statusline time;  ! We want the time, not the score

[	DrawStatusLine width posa posb;
	@split_window 2;
	@set_window 1;
	@set_cursor 1 1;
	style reverse;
	width = 0->33;
	posa = width - 14;
	posb = 2;
	spaces width;
	@set_cursor 2 1;
	spaces width;
	@set_cursor 1 2;
	style bold;
	print (name) location;
	style roman;
	style reverse;

	if (width > 76) {
		@set_cursor 1 posa;
		print (string) SCORE__TX, score;
		@set_cursor 2 posa;
		print (string) MOVES__TX, turns;
	} else if (width > 63) {
		@set_cursor 1 posa;
		print sline1, "/", sline2;
	}

	@set_cursor 2 posb;
	print (string) TIME__TX;
	LanguageTimeOfDay(sline1, sline2);
	print " on ", (string) day_table-->day;
	@set_cursor 1 1;
	style roman;
	@set_window 0;
];
