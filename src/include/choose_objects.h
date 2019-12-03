[	ChooseObjects obj code;
	if (code < 2) {
		if (obj has scenery or animate or door) {
			return 2;
    }

    rfalse;
	}

	if (action_to_be == ##Eat && obj has edible) {
		return 3;
  }

	if (obj hasnt scenery) {
		return 2;
  }

	return 1;
];
