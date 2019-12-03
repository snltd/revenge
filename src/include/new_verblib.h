! Additions and replacements to the standard Inform Grammar
! Requires New_Grammar.inf

[ BendSub;
	return M__M(##Bend);
];

[ BurstSub;
	return M__M(##Burst, noun);
];

[ CatchSub;
	return M__M(##Catch);
];

[ CantSub;
	rtrue;
];

[ CoverSub;
	return M__M(##Cover, noun, second);
];

[ CutSub;
	if (ObjectIsUntouchable(noun)) {
		return;
  }

	if (second hasnt cutter) {
		return M__M(##Cut, 2);
  }

	if (noun == player) {
		return M__M(##Cut, 1);
  }

	if (second == noun) {
		return M__M(##Cut, 3);
  }
];

[ DigSub;
	if (noun == 0) {
		return M__M(##Dig, 1);
  }

	if (noun hasnt digger) {
		return M__M(##Dig, 4, noun);
  }

	if (location hasnt outside) {
		return M__M(##Dig, 2);
  }

	return M__M(##Dig, 3);
];

[ CrushSub;
	return M__M(##Cant);
];

[ FeelUnderSub;
	return M__M(##Cant);
];

[ FillWithSub;
	return M__M(##Cant);
];


[ GoFishinSub;
	return M__M(##GoFishin);
];

[ HideSub;
	return M__M(##Cant);
];

[ InsertSub a;
	receive_action = ##Insert;

	if (second == d_obj) {
		<<Drop noun>>;
  }

	if (parent(noun) ~= player) {
		"You need to be holding ", (the) noun, " before you can do that.";
  }

	if (second > 1) {
		action = ##Receive;

		if (RunRoutines(second, before) ~= 0) {
			action = ##Insert;
			rtrue;
		}

		action = ##Insert;
	}

	if (second hasnt container) {
		return L__M(##Insert, 2);
  }

	if (second hasnt open) {
		return L__M(##Insert, 3);
  }

	if (IndirectlyContains(noun, second) == 1) {
		return L__M(##Insert, 5);
  }

	if (noun has worn) {
		L__M(##Insert, 6);
		<Disrobe noun>;

		if (noun has worn) {
			rtrue;
    }
	}

	if (OkSize(second, noun) == 0) {
		a = action;
		action = ##Insert;

		if (RunRoutines(second, too_big) == 0) {
			"There's not enough room for ", (the) noun, " in ", (the) second, ".";
    }

		action = a;

		if (ValueOrRun(noun, size) <= ValueOrRun(second, max_space)) {
			return AdvisePullIt(second);
    }

		rtrue;
	}

	if (OkWeight(second, noun) == 0) {
		a = action;
		action = ##Insert;

		if (RunRoutines(second, too_heavy) == 0) {
			print_ret (The) second, " couldn't support any more weight.";
    }

		action = a;

		if (ValueOrRun(noun, weight) <= ValueOrRun(second, max_weight)) {
			return AdvisePullIt(second);
    }

		rtrue;
	}

	move noun to second;

	if (AfterRoutines() == 1) {
		rtrue;
  }

	if (second > 1) {
		action = ##Receive;

		if (RunRoutines(second, after) ~= 0) {
			action = ##Insert;
			rtrue;
		}

		action = ##Insert;
	}

	if (keep_silent == 1) {
		rtrue;
  }

	if (multiflag == 1) {
		return L__M(##Insert, 8);
  }

	L__M(##Insert, 9, noun);
];

[ KickAtSub;
		if (noun in player) {
			return M__M(##KickAt, 1);
    }

		return M__M(##KickAt, 2);
];

[ KickOverSub;
		if (noun has footy) {
			return M__M(##KickOver, 1);
    }

		return M__M(##KickOver, 2);
];

[ KickThroughSub;
	return M__M(##KickThrough);
];

[ LBehindSub;
  if (noun in player) {
    return M__M(##Lbehind, 1, noun);
  }

  if (parent(noun) has animate) {
    return M__M(##Lbehind, 2, noun, parent(noun));
  }

  if (noun has scenery) {
    return M__M(##Lbehind, 3);
  }

  return M__M(##Lbehind, 4);
];

[ LookOverSub;
  if (noun in player) {
    return M__M(##LookOver, 1);
  }

  if (noun has portal) {
    return M__M(##LookOver, 2);
  }

  return M__M(##LookOver, 3);
];

[ LMode2Sub;
	lookmode=2;
	print (string) Story; L__M(##LMode2);
	print_box(23);
];

[ LsSub;
	return M__M(##Ls);
];

[ MakeSub;
	return M__M(##Make);
];

[ NoTopicSub;
	return M__M(##Question, 1, noun);
];

[ PierceSub;
	return M__M(##Pierce, noun, second);
];

[ PlantSub;
	return M__M(##Cant);
];

[ PointSub;
	if (noun in player) {
		return M__M(##Point, 1, noun, second);
  }

	if (noun has second) {
		return M__M(##Point, 2, noun);
  }

	if (noun has animate) {
		return M__M(##Point, 3, noun);
  }

	return M__M(##Point, 4);
];

[ PourSub;
	return M__M(##Cant);
];

[ PullWithSub;
	return M__M(##Cant);];

[ PushIntoSub;
	return M__M(##Cant);
];

[ PutOnSub a;
	receive_action = ##PutOn;

	if (second == d_obj) {
		<Drop noun>;
		rfalse;
	}

	if (parent(noun) ~= player) {
		return L__M(##PutOn, 1, noun);
  }

	if (second > 1) {
		action = ##Receive;

		if (RunRoutines(second, before) ~= 0) {
			action = ##PutOn;
			rtrue;
		}

		action = ##PutOn;
	}

	if (IndirectlyContains(noun, second) == 1) {
		return L__M(##PutOn, 2);
  }

	if (second hasnt supporter) {
		return L__M(##PutOn, 3, second);
  }

	if (parent(second) == player) {
		return L__M(##PutOn, 4);
  }

	if (noun has worn) {
		L__M(##PutOn, 5);
		<Disrobe noun>;

		if (noun has worn) {
			rtrue;
    }
	}

	if (OkSize(second, noun) == 0) {
		a = action;
		action = ##PutOn;

		if (RunRoutines(second, too_big) == 0) {
      "There isn't sufficient space for ", (the) noun, " on ", (the) second,
      ".";
    }

		action = a;

		if (ValueOrRun(noun, size)<=ValueOrRun(second, max_space)) {
			return AdviseMoveIt(second);
    }

		rtrue;
	}

	if (OkWeight(second, noun) == 0) {
		a = action;
		action = ##PutOn;

		if (RunRoutines(second, too_heavy) == 0) {
      "You feel ", (the) second, " begin to give as the weight of ", (the)
      noun, " is transferred to it. You withdraw ", (the) noun, ".";
		}

		action = a;

		if (ValueOrRun(noun, weight)<=ValueOrRun(second, max_weight)) {
			return AdviseMoveIt(second);
    }

		rtrue;
	}

	move noun to second;

	if (AfterRoutines() == 1) {
		rtrue;
  }

	if (second > 1) {
		action = ##Receive;

		if (RunRoutines(second, after) ~= 0) {
			action = ##PutOn;
			rtrue;
		}

		action = ##PutOn;
	}

	if (keep_silent == 1) {
		rtrue;
  }

	if (multiflag == 1) {
		return L__M(##PutOn, 7);
  }

	L__M(##PutOn, 8, noun);
];

[ RTakeSub fromobj i j k postonobj a rval;
	if (noun == player) {
		return L__M(##Take, 2);
  }

	if (noun has animate) {
		return L__M(##Take, 3, noun);
  }

	if (parent(player) == noun) {
		return L__M(##Take, 4, noun);
  }

	i=parent(noun);

	if (i == player) {
		return L__M(##Take, 5);
  }

	if (i has container || i has supporter) {
		postonobj = i;
		k = action;
		action = ##LetGo;

		if (RunRoutines(i, before) ~= 0) {
			action = k;
			rtrue;
		}

		action = k;
	}

	while (i ~= fromobj && i ~= 0) {
		if (i hasnt container && i hasnt supporter) {
			if (i has animate) {
				return L__M(##Take, 6, i);
      }

			if (i has transparent) {
				return L__M(##Take, 7, i);
      }

			return L__M(##Take, 8);
		}

		if (i has container && i hasnt open) {
			return L__M(##Take, 9, i);
    }

		i = parent(i);

		if (i == player) {
			i = fromobj;
    }
	}

	if (noun has scenery) {
		return L__M(##Take, 10);
  }

	if (noun has static) {
		return L__M(##Take, 11);
  }

	if (OkWeight(player, noun) == 0) {
		a = action;
		action = ##Take;
		rval = PrintOrRun(noun, too_heavy, 0);
		action = a;
		return rval;
	}

	if (OkSize(player, noun) == 0) {
		if (SACK_OBJECT ~= 0) {
			if (parent(SACK_OBJECT) ~= player) {
				return ObjTooBig(noun);
      }

			j = 0;
			objectloop (k in player) {
				if (k ~= SACK_OBJECT && k hasnt worn && k hasnt light) {
					j=k;
        }
      }

			if (j ~= 0) {
				L__M(##Take, 13, j);
				keep_silent = 1;
				<Insert j SACK_OBJECT>;
				keep_silent = 0;

				if (j notin SACK_OBJECT) {
					rtrue;
        }
			}
			else {
				return ObjTooBig(noun);
      }
		}
		else {
			return ObjTooBig(noun);
    }
	}

	move noun to player;

	if (postonobj ~= 0) {
		k = action;
		action = ##LetGo;

		if (RunRoutines(postonobj, after) ~= 0) {
			action = k;
			rtrue;
		}

		action = k;
	}

	rfalse;
];

[ ShaveSub;
	return M__M(##Shave);
];

[ ShootSub;
	if (second hasnt shooter) {
		return M__M(##Shoot, 1);
  }

	if (noun has animate) {
		return M__M(##Shoot, 2);
  }

	if (noun has scenery) {
		return M__M(##Shoot, 3);
  }
];

[ StrokeSub;
	return M__M(##Stroke, noun);
];

[ TieRoundSub;
	return M__M(##Cant);
];

[ TopicScope i;
	if (scope_stage == 1) {
		rfalse;
  }

 	if (scope_stage == 2) {
		objectloop (i ofclass Topic) {
			PlaceInScope(i);
    }

		rfalse;
	}
	else {
		NoTopicSub(i);
  }

	rfalse;
];

[ WhatScope i;
	if (scope_stage == 1) {
		rfalse;
  }

	if (scope_stage == 2) {
		objectloop (i provides whatsit) {
			PlaceInScope(i);
    }

		rfalse;
	}
	else {
		WhatIsSub(i);
  }
];

Class Topic
	with short_name "that",
	has	proper;

[ TieToSub;
	if (second hasnt stringy) {
		<<TieTo second noun>>;
  }

	return M__M(##TieTo, noun);
];

[ ThrowThroughSub;
	return M__M(##Cant);
];

[ TurnDownSub;
	return M__M(##TurnDown);
];

[ TurnUpSub;
	return M__M(##TurnUp);
];

[ UnplugSub;
	return M__M(##Unplug, noun);
];

[ UnscrewSub;
	return M__M(##Unscrew);
];

[ UnTieSub;
	return M__M(##UnTie, noun);
];

![	WaitHoursSub;
	!noun = noun * 60;
	!WaitMovesSub();
!];

![	WaitMovesSub i;

	!if (noun > MAX_WAIT) {
		!give tw_waiting locked;
		!"That's too long to wait.";
	!}

	!if (noun == 0) {
		!print "That didn't take long.^";
		!give tw_waiting locked;
		!rtrue;
	!}

	!if (noun == 1)
	!	<<Wait>>;

	!print "Time passes.^";
	!give tw_waiting ~on;
	!for (i = noun: (i > 1) && (deadflag == 0) && (tw_waiting hasnt on):
	!i--) {
		!InformLibrary.End_Turn_Sequence();
		!DisplayStatus();
		!DrawStatusLine();
	!}
	!if ((tw_waiting has on) && (i > 1) && (deadflag == 0))
		!print "^(waiting stopped)^";
!];

![	WaitUntilSub;
	!if (parsed_number >= the_time) noun = parsed_number-the_time;
	!if (parsed_number < the_time) {
		!parsed_number = the_time-parsed_number;
		!noun = 1440 - parsed_number;
		!print "(tomorrow)^^";
	!}
	!WaitMovesSub();
!];

[ WaterSub;
	return M__M(##water);
];

[ WhatIsSub;
	if (noun == player) {
		<<WhoAmI>>;
  }

	if (noun provides whatsit) {
		PrintOrRun(noun, whatsit);
		rtrue;
	}
	else {
		print (string) random("Good question.^",
                          "Who knows?^",
                          "I wonder...^",
                          "Search me.^");
  }
];

[ WhatIsWhatSub;
	if (verb_word == 'who') {
		print "Who";
  }
	else {
		print "What";
  }

	" is what?";
];

[ WhatsSub;
	return M__M(##whats);
];

[ WhoAmISub;
	if (player has general) {
		return M__M(##WhoAmI, 1);
  }

	return M__M(##WhoAmI, 2);
];

[	DiagnoseSub;
	if (player has general) {
		"You are pretty well hammered.";
  }

	"You don't have your medical dictionary with you.";
];

[	xyzzySub;
	"Still believing in magic at your age?";
];

[ KnockSub;
	if (noun has portal) {
		return M__M(##Knock, 1);
  }

	return M__M(##Knock, 2);
];

[ LookDirSub;
	if (noun in Compass) {
		Peeking(location, noun.door_dir);
  }
	else {
		<<examine noun>>;
  }
];

[ Responses n x1 x2;
	Bend:
    "You're not strong enough.";
	Burst:
    "You can't burst ", (a) x1, "!";
	Catch:
    "I don't think you need to.";
	Cant:
    "You can't.";
	Cover:
    print_ret (The) x1, " won't cover ", (the) x2, ".";
	Cut:
    switch(n) {
      1:
        "Is that a cry for help?";
      2:
        "You can't cut anything with that.";
      3:
        "You can't cut something with itself!";
    }
	Dig:
    switch(n) {
      1:
        "You'll have to state where and with what.";
      2:
        "You can't dig indoors.";
      3:
        "Despite the recent rain, the ground here is too hard.";
      4:
        "You can't dig with ", (a) x1, ".";
    }
	GoFishin:
    "Virtual fishing. It's what computers were made for.";
	KickAt:
    switch(n) {
      1:
        "Not while you're holding it.";
      2:
        "You're rubbish at football: you'd probably miss.";
    }
	KickOver:
    switch(n) {
      1:
        "Your aim is probably not good enough.";
      2:
        "You could hurt your toe trying that.";
    }
	KickThrough:
    "That would have to be one hell of a kick.";
	Knock:
    switch(n) {
      1:
        "There is no response.";
      2:
        "Nothing happens.";
    }
	Lbehind:
    switch(n) {
      1:
        "But you are holding ", (the) x1, ".";
      2:
        "That belongs to ", (the) x2, ".";
      3:
        "You find nothing of interest.";
      4:
        "You can't look behind that.";
    }
	LookOver:
    switch(n) {
      1:
        "You don't have to: it doesn't block your normal line of sight.";
      2:
        "That's daft.";
      3:
        "You see nothing you didn't see before.";
    }
	Ls:
    "Yeah, I type that sometimes when I mean to type ~l~. Too much Unix.";
	Make:
    "Looks as though someone's already made it.";
	Pierce:
    "You can't put ", (a) x1, " through ", (a) x2, ".";
	Point:
    switch(n) {
      1:
        "You aim ", (the) x1, " vaguely in the direction of ", (the) x2, ".";
      2:
        print_ret (The) x1, " is fixed in place.";
      3:
        "I don't think ", (the) x1, " would let you try that.";
      4:
        "Why exactly? (Don't answer that.)";
    }
	Shave:
    "You don't need a shave.";
	Shoot:
    switch(n) {
      1:
        "I can see the headlines now: Man shoots ", (name) x1, " with ",
        (name) x2, ".";
      2:
        "That would be murder.";
      3:
        "Shooting up the scenery won't help you any.";
    }
	Stroke:
    "There's a good ", (name) x1, ".";
	TieTo:
    "You can't tie knots in ", (a) x1, ".";
	TurnDown:
    "You can't turn that down.";
	TurnUp:
    "You can't turn that up.";
	Unplug:
    "When have you seen ", (a) x1, " that you plugged in?";
	Unscrew:
    "You can't unscrew that.";
	Untie:
    print_ret (The) x1, " doesn't appear to have a knot in it.";
	Water:
    "You'd only get it all wet.";
	Whats:
    "If you don't know I'm not going to tell you.";
	WhoAmI:
    switch(n) {
      1:
        "You're not too sure right now.";
      2:
        "Come now, your accident wasn't that bad.";
    }
];

[ M__M act n x1 s;
	s = sw__var;
	sw__var = act;

	if (n == 0) {
    n = 1;
  }

	M___M(n, x1);
	sw__var = s;
];

[ M___M n x1 s;
	s = action;
	lm_n = n;
	lm_o = x1;
	action = sw__var;

	if (RunRoutines(LibraryMessages, before) ~=  0) {
		action = s;
		rfalse;
	}

	action = s;
	Responses(n, x1);
];
