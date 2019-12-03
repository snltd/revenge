!=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
!
! House.h - version 2.0
!
! (c) 1998 Robert Fisher
!
! Classes and routines to more easily build a house and garden
!
! This may be used in any way you like. It may work, it may not. I take no
! responsibility for any problems, frustrations or personal injuries this
! software causes.
!
! If you wish to use my "weather.h" module, in conjunction with this code,
! uncomment the line containing DEFINE HAVE_WEATHER and include weather.h
! *AFTER* this file.
!
! You will need to use my "person.h" for the Person class it contains. The
! property "peekdesc" is included in it.
!
! If your game uses Sam Hulick's excellent "Physics.h", search for and
! uncomment all the lines defining "size" and "weight" properties.
!
! Be sure to uncomment and move the additions to the Grammar found at the
! end of this file.
!
!=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

Constant HAVE_WEATHER;

Constant HAVE_HOUSE_H;

#IFDEF DEBUG;
  Message "Compiling module house.h";
#ENDIF;

Attribute outside;    ! Give all your outdoor locations this attribute.
Attribute upstairs;   ! Give all your upstairs locations this attribute.
                      ! It's needed by the stairs class, but I've found it
                      ! useful for all manner of things.
Attribute broken;     ! This is so you can break windows.
Attribute flagged;    ! A general purpose attribute

Property underfoot 0; ! For that all important "examine floor". Set this to
                      ! whatever Object the floor should be set to
Property overhead 0;  ! And the even more important "look up". Points to
                      ! the ceiling/sky object for a location
Property inloc 0;     ! Needed for the Portal class - it's the name of the
                      ! location "behind" a door. The name arises because
                      ! if you have, say a front door, inloc could be the
                      ! location inside the house. It can get a little
                      ! confusing for doors inside a house though!
Property indir 0;     ! The direction in which you go through a Portal to
                      ! reach it's inloc
!Property outloc 0;   ! The room on the other side of a Portal's inloc
!Property outdir 0;   ! Analagous to indir

!=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
!
! You create a room (or an outside location) using the properties underfoot,
! overhead, wall and locname as illustrated in the class. Because they're in the
! class, you can of course leave any of them out of your rooms and get the
! default value.
!
!=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

Class Place with
  underfoot new_floor,   ! you might want to change this,
  overhead new_ceiling,  ! this,
  wall new_wall,         ! and this
  locname "D'oh! You've forgotten the location name.",
  ! locname provides another name for rooms, used to tell the player the
  ! name of a location on a given direction.  For instance, the kitchen in
  ! the player's house may have the name "Kitchen". "To the north is
  ! Kitchen" looks pretty silly, so locname is used to print a more sensible
  ! message like "To the north is the kitchen"
  onwalls "The walls are undecorated.",
  has light;

! Other properties a room may have:
!
! onwalls  Allows you to decorate your rooms. A description of what is on
!      them, say flock wallpaper, wood panelling or whatever, may be
!      held in a string or a routine

!=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
!
! This class is used for "see through" objects, like doors, windows and anything
! else the player might conceivably "look through".
!
!=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

Class glass with
  before [;
    Search:
      if (location == self.inloc) {
        Peeking(location, self.outdir);
      }
      else {
        Peeking(location, self.indir);
      }

      rtrue;
  ];

!=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
!
! Use this class for any connection that the player can physically pass through.
! It will usually be a door, but obviously I couldn't call the class "door"
! because that's a reserved word.
!
!=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

Class portal class glass with
  ! has class glass so you can see through it (at least when it's open)
  name "door" "portal" "doorway" "doors//p" "portals//p" "doorways//p",
  before [;
    LookUnder:
      if (self has open) {
        "It's open: just look through it.";
      }

      "There isn't enough of a gap to see anything.";
    Knock:
      "There is no reply.";
  ],
  door_to [;
    if (location == self.inloc) {
      return self.outLoc;
    }
    else {
      return self.inloc;
    }
  ],
  door_dir [;
    if (location == self.inloc) {
      return self.outdir;
    }
    else {
      return self.indir;
    }
  ],
  describe [;
    rtrue;
  ],
  outloc 0,
  outdir 0,
  size 30,        ! uncomment this if you are using Physics.h
  weight 30,      ! uncomment this if you are using Physics.h
  has openable static door;

!=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
!
! So, to put a door in your game, create a portal object with the properties
! InLoc, and OutLoc. These are the locations "inside" and "outside" the door.
! Then add the properties InDir and OutDir which take the player to InLoc and
! OutLoc respectively from the other location. You also need to tell Inform that
! your new door is found_in InLoc and OutLoc. An example might be clearer:
!
! Portal front_door "front door"
!   with name "front",
!  InLoc hall, OutLoc garden_path,
!  InDir n_to, OutDir s_to,
!  found_in hall garden_path;
!
!=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

Class key class adnc with
  name "key" "keys//p",
  adname 'door',
  before [;
    Eat:
      "And unlock your inner self no doubt.";
    !PutOn:
      !if (second == key_ring) {
        !move self to key_ring;
        !"You slip ", (the) self, " onto ", (the)
        !second, ".";
      !}
  ],
  !size 0,        ! uncomment this if you are using Physics.h
  !weight 0,        ! uncomment this if you are using Physics.h
  has metallic;

!=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
!
! Windows can be seen through, opened and closed, but not passed through. For a
! window that the player can pass through, use the Portal class.
!
!=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

Class window class glass with
  name "window" "pane" "of" "glass" "panes//p" "windows//p",
  before [where;
    Open:
      if (self has open) {
        "The", name (self), " is already open.";
      }
    Attack:
      if (self has broken) {
        "It's broken already.";
      }
      else {
        give self broken;
        print "Sharply, you rap the glass with your elbow. The glass shatters
        and falls ";

        if (location == self.outloc) {
          where = self.inloc;
        }
        else {
          where = self.outloc;
        }

        if (where has outside) {
          print "to the ground outside.";
        }
        else {
          print "into ";

          if (where provides locname) {
            print where.locname;
          }
          else {
            print "another place";
          }
          print ".";
        }

        " Remarkably, you have managed not to cut yourself.";
      }
];

!=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
!
! Unless your game is set in a bungalow, you might find it useful to have a
! flight of stairs at your disposal. If so, use this class.
!
!=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

Class Stairs with
  name "stair" "case" "stairs" "staircase" "newell" "post" "bannister",
  before [;
    Climb:
      <<go self>>;
    LookUnder:
      "Bizarre.";
    Take:
      "You want to pick up and carry off a flight of stairs?";
  ],
  door_to [;
    if (location == self.inloc) {
      return self.outloc;
    }

    return self.inloc;
  ],
  door_dir [;
    if (location == self.inloc) {
      return d_to;
    }

    return u_to;
  ],
  describe [;
    rtrue;
  ],
  has static door open;

!=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
!
! The default floor, roof and walls for the Place class, both in and out of
! doors. You'll probably need to edit these to suit the location of your game.
!
!=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

Class Floor with
  name "floor" "ground" "earth" "underfoot" "firmament",
  description [;
    if (location has outside) {
      "The ground is damp from the recent rain.";
    }

    "The floor is cheaply carpeted.";
  ],
  has scenery;

Class Roof with
  name "roof" "ceiling",
  parse_name [;
    if (NextWord() == 'ceiling') {
      return 2;
    }

    return 0;
  ],
  before [;
    LookUnder:
      "Under the ceiling is...the room!";
    Take:
      "I thought it was so unlikely that anyone would try that that I didn't
      even bother to put in a clever response.";
  ],
  description "Painted white.",
  has scenery;

Object new_wall "wall" with
  name "wall" "walls",
  description [;
    if (location has outside) {
      "The house wall is built of discoloured red brick.";
    }

    if (location provides onwalls) {
      PrintOrRun(location, onwalls);
    }

    "As you would expect.";
  ],
  has scenery;

Floor new_floor "floor" with
  name "floor"
  has scenery;

Roof new_ceiling "ceiling";

[ Peeking here direc tion there x y z the_place destination obj;
  ! the_place is a variable holding parent(player) inserted to
  ! work around compilation problems with Inform 6.15
  the_place = parent(player);

  objectloop(obj ofclass CompassDirection) {
    if (obj.door_dir == direc) {
      tion = obj;
      break;
    }
  }

  ! so, for example:
  !  direc = ne_to
  !  tion  = ne_obj [ northeast ]

  there = here.direc;    ! the object being looked at

  if ((ZRegion(there) == 0 or 3) && (noun ~= u_obj or d_obj)) {
    "You see nothing noteworthy.";
  }

  if ((ZRegion(there) == 1) && (there ofclass Place)) {
    print  "To the ";
    LanguageDirection(tion);
    print " is ";
    jump name_who;
  }

  if (there ofclass stairs) {
    print "At the ";

    if (here == there.outloc) {
      print "top";
    }
    else {
      print "foot";
    }

    print " of the stairs you can see ";
    jump name_who;
  }

  if (noun == u_obj) {
    <<examine the_place.overhead>>;
  }

  if (noun == d_obj) {
    <<examine the_place.underfoot>>;
  }

  if (there ofclass portal) {
    if (there hasnt open && there hasnt flagged) {
      "You can see only the closed ", (name) there, ".";
    }

    if (there hasnt flagged) {
      print "T";
    }
    else {
      print "Peering t";
    }

    print "hrough ", (the) there, " you can see ";

    if (location == there.outloc) {
      destination = there.inloc;
    }
    else {
      destination = there.outloc;
    }

    if (destination hasnt outside) {
      print "into ";
    }

    jump name_who;
  }

  print_ret "nothing special";

  .name_who;

  if (there ofclass portal) {
    if (the_place == there.inloc) {
      there = there.outloc;
    }
    else {
      if (the_place == there.outloc) {
        there = there.inloc;
      }
    }
  }

  if (there provides locname) {
    print (string) there.locname;
  }
  else {
    print "another place";
  }

  y = 0;

  objectloop (x in there) {
!   if (x ofclass person)
    if (x has animate) {
      y++;
    }
  }

  if (y == 0) {
    ".";
  }

  z = 0;

  objectloop (x in there) {
!   if (x ofclass person) {
    if (x has animate) {
      z++;

      if (z == 1) {
        print ", where ";
      }

      if (z == y && z ~= 1) {
        print " and ";
      }

      if (z ~= y && z > 1) {
        print ", ";
      }

      print (name) x, " ";
      PrintOrRun(x, peekdesc, 1);
    }
  }
  print ".^";
  rtrue;
];

![  Other_Room room;
  !
  !if (real_location == room.inloc)
    !return room.outloc;
  !else
    !return room.inloc;
!!];

!=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
!
! This code was written on a Commodore Amiga A4000/040
!
!=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
