% This file contains the ALists from ofsfvslists.red in a more
% readable form. Compilation for PSL of these ALists in this form
% causes problems. Therefore, we decided to paste a "static" version
% of these ALists into the file ofsfvslists.red and keep the originals
% here for reference.

%%% rsl-alist %%%

rsl!-alist!* := {
   % key: {ldeg f, sign of lc f, op}
   % value: AList [al] containing elements [pr] such that [car pr] is
   % one of ['(ip ep slb wlb sub wub)] and [cdr pr] is a list of root
   % specification lists
   {1, -1, 'equal} . {
      'ip . {
	 {(-1) . 1}
	    }
	       },

   {1, nil, 'equal} . {
      'ip . {
	 {1 . 1},
      	 {(-1) . 1}
	    }
	       },

   {1, 1, 'equal} . {
      'ip . {
	 {1 . 1}
	    }
	       },

   {1, -1, 'neq} . {
      'ep  . {
	 {(-1) . 1}
	    }
	       },

   {1, nil, 'neq} . {
      'ep . {
	 {1 . 1},
      	 {(-1) . 1}
	    }
	       },

   {1, 1, 'neq} . {
      'ep . {
	 {1 . 1}
	    }
	       },

   {1, -1, 'lessp} . {
      'slb . {
	 {(-1) . 1}
	    }
	       },

   {1, nil, 'lessp} . {
      'slb . {
	 {(-1) . 1}
	    },
      'sub . {
	 {1 . 1}
	    }
	       },

   {1, 1, 'lessp} . {
      'sub . {
	 {1 . 1}
	    }
      	       },

   {1, -1, 'leq} . {
      'wlb . {
	 {(-1) . 1}
	    }
	       },

   {1, nil, 'leq} . {
      'wlb . {
      	 {(-1) . 1}
	    },
      'wub . {
	 {1 . 1}
	    }
      	       },

   {1, 1, 'leq} . {
      'wub . {
	 {1 . 1}
	    }
	       },

   {1, -1, 'geq} . {
      'wub . {
	 {(-1) . 1}
	    }
      	       },
   {1, nil, 'geq} . {
      'wlb . {
	 {1 . 1}
	    },
      'wub . {
	 {(-1) . 1}
	    }
	       },

   {1, 1, 'geq} . {
      'wlb . {
	 {1 . 1}
	    }
	       },

   {1, -1, 'greaterp} . {
      'sub . {
      	 {(-1) . 1}
	    }
      	       },

   {1, nil, 'greaterp} . {
      'slb . {
      	 {1 . 1}
	    },
      'sub . {
      	 {(-1) . 1}
	    }
	       },

   {1, 1, 'greaterp} . {
      'slb . {
      	 {1 . 1}
	    }
	       },

   {2, -1, 'equal} . {
      'ip . {
      	 {(-1) . 1},
      	 {(-1) . 2},
      	 {(-2) . 1}
	    }
	       },

   {2, nil, 'equal} . {
      'ip . {
	 {1 . 1},
      	 {1 . 2},
      	 {2 . 1},
      	 {(-1) . 1},
      	 {(-1) . 2},
      	 {(-2) . 1}
	    }
	       },

   {2, 1, 'equal} . {
      'ip . {
      	 {1 . 1},
      	 {1 . 2},
      	 {2 . 1}
	    }
	       },

   {2, -1, 'neq} . {
      'ep . {
      	 {(-1) . 1},
      	 {(-1) . 2},
      	 {(-2) . 1}
	    }
	       },

   {2, nil, 'neq} . {
      'ep . {
	 {1 . 1},
      	 {1 . 2},
      	 {2 . 1},
      	 {(-1) . 1},
      	 {(-1) . 2},
      	 {(-2) . 1}
	    }
	       },

   {2, 1, 'neq} . {
      'ep . {
      	 {1 . 1},
      	 {1 . 2},
      	 {2 . 1}
	    }
	       },

   {2, -1, 'lessp} . {
      'ep . {
	 {(-2) . 1}
	    },
      'slb . {
      	 {(-1) . 2}
	    },
      'sub . {
	 {(-1) . 1}
	    }
	       },

   {2, nil, 'lessp} . {
      'ep . {
	 {(-2) . 1}
	    },
      'slb . {
      	 {1 . 1},
	 {(-1) . 2}
	    },
      'sub . {
	 {1 . 2},
      	 {(-1) . 1}
	    }
	       },

   {2, 1, 'lessp} . {
      'slb . {
      	 {1 . 1}
	    },
      'sub . {
      	 {1 . 2}
	    }
	       },

   {2, -1, 'leq} . {
      'wlb . {
      	 {(-1) . 2}
	    },
      'wub . {
	 {(-1) . 1}
	    }
	       },

   {2, nil, 'leq} . {
      'ip . {
      	 {2 . 1}
	    },
      'wlb . {
      	 {1 . 1},
      	 {(-1) . 2}
	    },
      'wub . {
	 {1 . 2},
      	 {(-1) . 1}
	    }
	       },

   {2, 1, 'leq} . {
      'ip . {
      	 {2 . 1}
	    },
      'wlb . {
      	 {1 . 1}
	    },
      'wub . {
	 {1 . 2}
	    }
	       },

   {2, -1, 'geq} . {
      'ip . {
	 {(-2) . 1}
	    },
      'wlb . {
      	 {(-1) . 1}
	    },
      'wub . {
	 {(-1) . 2}
	    }
	       },

   {2, nil, 'geq} . {
      'ip . {
	 {(-2) . 1}
	    },
      'wlb . {
      	 {1 . 2},
      	 {(-1) . 1}
	    },
      'wub . {
	 {1 . 1},
      	 {(-1) . 2}
	    }
	       },

   {2, 1, 'geq} . {
      'wlb . {
      	 {1 . 2}
	    },
      'wub . {
	 {1 . 1}
	    }
	       },

   {2, -1, 'greaterp} . {
      'slb . {
      	 {(-1) . 1}
	    },
      'sub . {
	 {(-1) . 2}
	    }
	       },

   {2, nil, 'greaterp} . {
      'ep . {
      	 {2 . 1}
	    },
      'slb . {
      	 {1 . 2},
      	 {(-1) . 1}
	    },
      'sub . {
      	 {1 . 1},
      	 {(-1) . 2}
	    }
	       },

   {2, 1, 'greaterp} . {
      'ep . {
	 {2 . 1}
	    },
      'slb . {
      	 {1 . 2}
	    },
      'sub . {
	 {1 . 1}
	    }
	       },

   {3, -1, 'equal} . {
      'ip . {
	 {(-1) . 1},
      	 {(-2) . 1},
      	 {(-2) . 2},
      	 {(-3) . 1},
      	 {(-3) . 2},
      	 {(-4) . 1},
      	 {(-4) . 2},
      	 {(-4) . 3}
	    }
	       },

   {3, nil, 'equal} . {
      'ip . {
      	 {1 . 1},
      	 {2 . 1},
      	 {2 . 2},
      	 {3 . 1},
      	 {3 . 2},
      	 {4 . 1},
      	 {4 . 2},
      	 {4 . 3},
      	 {(-1) . 1},
      	 {(-2) . 1},
      	 {(-2) . 2},
      	 {(-3) . 1},
      	 {(-3) . 2},
      	 {(-4) . 1},
      	 {(-4) . 2},
      	 {(-4) . 3}
	    }
	       },

   {3, 1, 'equal} . {
      'ip . {
	 {1 . 1},
      	 {2 . 1},
      	 {2 . 2},
      	 {3 . 1},
      	 {3 . 2},
      	 {4 . 1},
      	 {4 . 2},
      	 {4 . 3}
	    }
	       },

   {3, -1, 'neq} . {
      'ep . {
      	 {(-1) . 1},
      	 {(-2) . 1},
      	 {(-2) . 2},
      	 {(-3) . 1},
      	 {(-3) . 2},
      	 {(-4) . 1},
      	 {(-4) . 2},
      	 {(-4) . 3}
	    }
	       },
   {3, nil, 'neq} . {
      'ep . {
      	 {1 . 1},
      	 {2 . 1},
      	 {2 . 2},
      	 {3 . 1},
      	 {3 . 2},
      	 {4 . 1},
      	 {4 . 2},
      	 {4 . 3},
      	 {(-1) . 1},
      	 {(-2) . 1},
      	 {(-2) . 2},
      	 {(-3) . 1},
      	 {(-3) . 2},
      	 {(-4) . 1},
      	 {(-4) . 2},
      	 {(-4) . 3}
	    }
	       },

   {3, 1, 'neq} . {
      'ep . {
      	 {1 . 1},
      	 {2 . 1},
      	 {2 . 2},
      	 {3 . 1},
      	 {3 . 2},
      	 {4 . 1},
      	 {4 . 2},
      	 {4 . 3}
	    }
	       },

   {3, -1, 'lessp} . {
      'ep . {
	 {(-3) . 2}
	    },
      'slb . {
      	 {(-1) . 1},
      	 {(-2) . 2},
      	 {(-3) . 1},
      	 {(-4) . 1},
      	 {(-4) . 3}
	    },
      'sub . {
	 {(-4) . 2}
	    }
	       },

   {3, nil, 'lessp} . {
      'ep . {
	 {2 . 1},
	 {(-3) . 2}
	    },
      'slb . {
      	 {4 . 2},
      	 {(-1) . 1},
      	 {(-2) . 2},
      	 {(-3) . 1},
      	 {(-4) . 1},
      	 {(-4) . 3}
	    },
      'sub . {
      	 {1 . 1},
      	 {2 . 2},
      	 {3 . 1},
      	 {4 . 1},
      	 {4 . 3},
      	 {(-4) . 2}
	    }
	       },

   {3, 1, 'lessp} . {
      'ep . {
      	 {2 . 1}
	    },
      'slb . {
      	 {4 . 2}
	    },
      'sub . {
	 {1 . 1},
      	 {2 . 2},
      	 {3 . 1},
      	 {4 . 1},
      	 {4 . 3}
	    }
	       },

   {3, -1, 'leq} . {
      'ip . {
      	 {(-2) . 1}
	    },
      'wlb . {
      	 {(-1) . 1},
      	 {(-2) . 2},
      	 {(-3) . 1},
      	 {(-4) . 1},
      	 {(-4) . 3}
	    },
      'wub . {
	 {(-4) . 2}
	    }
	       },

   {3, nil, 'leq} . {
      'ip . {
      	 {3 . 2},
      	 {(-2) . 1}
	    },
      'wlb . {
      	 {4 . 2},
      	 {(-1) . 1},
      	 {(-2) . 2},
      	 {(-3) . 1},
      	 {(-4) . 1},
      	 {(-4) . 3}
	    },
      'wub . {
	 {1 . 1},
      	 {2 . 2},
      	 {3 . 1},
      	 {4 . 1},
      	 {4 . 3},
      	 {(-4) . 2}
	    }
      	       },

   {3, 1, 'leq} . {
      'ip . {
	 {3 . 2}
	    },
      'wlb . {
      	 {4 . 2}
	    },
      'wub . {
	 {1 . 1},
      	 {2 . 2},
      	 {3 . 1},
      	 {4 . 1},
      	 {4 . 3}
	    }
	       },

   {3, -1, 'geq} . {
      'ip . {
      	 {(-3) . 2}
	    },
      'wlb . {
      	 {(-4) . 2}
	    },
      'wub . {
      	 {(-1) . 1},
      	 {(-2) . 2},
      	 {(-3) . 1},
      	 {(-4) . 1},
      	 {(-4) . 3}
	    }
      	       },

   {3, nil, 'geq} . {
      'ip . {
      	 {2 . 1},
      	 {(-3) . 2}
	    },
      'wlb . {
      	 {1 . 1},
      	 {2 . 2},
      	 {3 . 1},
      	 {4 . 1},
      	 {4 . 3},
      	 {(-4) . 2}
	    },
      'wub . {
      	 {4 . 2},
      	 {(-1) . 1},
      	 {(-2) . 2},
      	 {(-3) . 1},
      	 {(-4) . 1},
      	 {(-4) . 3}
	    }
      	       },

   {3, 1, 'geq} . {
      'ip . {
      	 {2 . 1}
	    },
      'wlb . {
      	 {1 . 1},
      	 {2 . 2},
      	 {3 . 1},
      	 {4 . 1},
      	 {4 . 3}
	    },
      'wub . {
      	 {4 . 2}
	    }
      	       },

   {3, -1, 'greaterp} . {
      'ep . {
	 {(-2) . 1}
	    },
      'slb . {
      	 {(-4) . 2}
	    },
      'sub . {
      	 {(-1) . 1},
      	 {(-2) . 2},
      	 {(-3) . 1},
      	 {(-4) . 1},
      	 {(-4) . 3}
	    }
	       },

   {3, nil, 'greaterp} . {
      'ep . {
      	 {3 . 2},
	 {(-2) . 1}
	    },
      'slb . {
      	 {1 . 1},
      	 {2 . 2},
      	 {3 . 1},
      	 {4 . 1},
      	 {4 . 3},
      	 {(-4) . 2}
	    },
      'sub . {
      	 {4 . 2},
      	 {(-1) . 1},
      	 {(-2) . 2},
      	 {(-3) . 1},
      	 {(-4) . 1},
      	 {(-4) . 3}
	    }
	       },

   {3, 1, 'greaterp} . {
      'ep . {
      	 {3 . 2}
	    },
      'slb . {
      	 {1 . 1},
      	 {2 . 2},
      	 {3 . 1},
      	 {4 . 1},
      	 {4 . 3}
	    },
      'sub . {
      	 {4 . 2}
	    }
	       }
   	    	  };

%%% rsl-alist-clustering %%%

rsl!-alist!-clustering!* := {
   % key: {ldeg f, sign of lc f, op}
   % value: AList [al] containing elements [pr] such that [car pr] is
   % one of ['(ip ep slb wlb sub wub)] and [cdr pr] is a list of root
   % specification lists
   {1, -1, 'equal} . {
      'ip . {
      	 {(-1) . 1}
	    }
	       },

   {1, nil, 'equal} . {
      'ip . {
	 {1 . 1, (-1) . 1}
	    }
	       },

   {1, 1, 'equal} . {
      'ip . {
	 {1 . 1}
	    }
	       },

   {1, -1, 'neq} . {
      'ep . {
	 {(-1) . 1}
	    }
	       },

   {1, nil, 'neq} . {
      'ep . {
	 {1 . 1, (-1) . 1}
	    }
	       },

   {1, 1, 'neq} . {
      'ep . {
	 {1 . 1}
	    }
	       },

   {1, -1, 'lessp} . {
      'slb . {
      	 {(-1) . 1}
	    }
	       },

   {1, nil, 'lessp} . {
      'slb . {
      	 {(-1) . 1}
	    },
      'sub . {
	 {1 . 1}
	    }
	       },

   {1, 1, 'lessp} . {
      'sub . {
	 {1 . 1}
	    }
	       },

   {1, -1, 'leq} . {
      'wlb . {
      	 {(-1) . 1}
	    }
	       },

   {1, nil, 'leq} . {
      'wlb . {
      	 {(-1) . 1}
	    },
      'wub . {
	 {1 . 1}
	    }
	       },

   {1, 1, 'leq} . {
      'wub . {
	 {1 . 1}
      	    }
	       },

   {1, -1, 'geq} . {
      'wub . {
      	 {(-1) . 1}
	    }
      	       },

   {1, nil, 'geq} . {
      'wlb . {
	 {1 . 1}
	    },
      'wub . {
      	 {(-1) . 1}
	    }
	       },

   {1, 1, 'geq} . {
      'wlb . {
	 {1 . 1}
	    }
	       },

   {1, -1, 'greaterp} . {
      'sub . {
      	 {(-1) . 1}
	    }
	       },

   {1, nil, 'greaterp} . {
      'slb . {
	 {1 . 1}
	    },
      'sub . {
      	 {(-1) . 1}
	    }
	       },

   {1, 1, 'greaterp} . {
      'slb . {
	 {1 . 1}
	    }
	       },

   {2, -1, 'equal} . {
      'ip . {
	 {(-1) . 2, (-2) . 1},
      	 {(-1) . 1, (-2) . 1}
	    }
	       },

   {2, nil, 'equal} . {
      'ip . {
	 {1 . 1, 2 . 1, (-1) . 2, (-2) . 1},
      	 {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}
	    }
	       },

   {2, 1, 'equal} . {
      'ip . {
      	 {1 . 1, 2 . 1},
      	 {1 . 2, 2 . 1}
	    }
	       },

   {2, -1, 'neq} . {
      'ep . {
	 {(-1) . 2, (-2) . 1},
      	 {(-1) . 1, (-2) . 1}
	    }
	       },

   {2, nil, 'neq} . {
      'ep . {
      	 {1 . 1, 2 . 1, (-1) . 2, (-2) . 1},
      	 {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}
	    }
	       },

   {2, 1, 'neq} . {
      'ep . {
      	 {1 . 1, 2 . 1},
      	 {1 . 2, 2 . 1}
	    }
	       },

   {2, -1, 'lessp} . {
      'slb . {
	 {(-1) . 2, (-2) . 1}
	    },
      'sub . {
	 {(-1) . 1, (-2) . 1}
	    }
	       },

   {2, nil, 'lessp} . {
      'slb . {
      	 {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}
	    },
      'sub . {
	 {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}
	    }
	       },

   {2, 1, 'lessp} . {
      'slb . {
      	 {1 . 1, 2 . 1}
	    },
      'sub . {
	 {1 . 2, 2 . 1}
	    }
	       },

   {2, -1, 'leq} . {
      'wlb . {
	 {(-1) . 2, (-2) . 1}
	    },
      'wub . {
	 {(-1) . 1, (-2) . 1}
	    }
	       },

   {2, nil, 'leq} . {
      'wlb . {
      	 {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}
	    },
      'wub . {
	 {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}
	    }
      	       },

   {2, 1, 'leq} . {
      'wlb . {
	 {1 . 1, 2 . 1}
	    },
      'wub . {
	 {1 . 2, 2 . 1}
	    }
	       },

   {2, -1, 'geq} . {
      'wlb . {
	 {(-1) . 1, (-2) . 1}
	    },
      'wub . {
	 {(-1) . 2, (-2) . 1}
	    }
	       },

   {2, nil, 'geq} . {
      'wlb . {
	 {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}
	    },
      'wub . {
	 {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}
	    }
	       },

   {2, 1, 'geq} . {
      'wlb . {
	 {1 . 2, 2 . 1}
	    },
      'wub . {
	 {1 . 1, 2 . 1}
	    }
	       },

   {2, -1, 'greaterp} . {
      'slb . {
	 {(-1) . 1, (-2) . 1}
	    },
      'sub . {
	 {(-1) . 2, (-2) . 1}
	    }
	       },

   {2, nil, 'greaterp} . {
      'slb . {
	 {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}
	    },
      'sub . {
	 {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}
	    }
      	       },

   {2, 1, 'greaterp} . {
      'slb . {
	 {1 . 2, 2 . 1}
	    },
      'sub . {
	 {1 . 1, 2 . 1}
	    }
	       },

   {3, -1, 'equal} . {
      'ip . {
	 {(-1) . 1},
      	 {(-2) . 1, (-3) . 1, (-4) . 1},
      	 {(-2) . 1, (-3) . 2, (-4) . 2},
      	 {(-2) . 2, (-3) . 2, (-4) . 3}
	    }
	       },

   {3, nil, 'equal} . {
      'ip . {
	 {1 . 1},
      	 {2 . 1, 3 . 1, 4 . 1},
      	 {2 . 1, 3 . 2, 4 . 2},
      	 {2 . 2, 3 . 2, 4 . 3},
      	 {(-1) . 1},
      	 {(-2) . 1, (-3) . 1, (-4) . 1},
      	 {(-2) . 1, (-3) . 2, (-4) . 2},
      	 {(-2) . 2, (-3) . 2, (-4) . 3}
	    }
	       },

   {3, 1, 'equal} . {
      'ip . {
	 {1 . 1},
      	 {2 . 1, 3 . 1, 4 . 1},
      	 {2 . 1, 3 . 2, 4 . 2},
      	 {2 . 2, 3 . 2, 4 . 3}
      	    }
	       },

   {3, -1, 'neq} . {
      'ep . {
	 {(-1) . 1},
      	 {(-2) . 1, (-3) . 1, (-4) . 1},
      	 {(-2) . 1, (-3) . 2, (-4) . 2},
      	 {(-2) . 2, (-3) . 2, (-4) . 3}
	    }
	       },

   {3, nil, 'neq} . {
      'ep . {
	 {1 . 1},
      	 {2 . 1, 3 . 1, 4 . 1},
      	 {2 . 1, 3 . 2, 4 . 2},
      	 {2 . 2, 3 . 2, 4 . 3},
      	 {(-1) . 1},
      	 {(-2) . 1, (-3) . 1, (-4) . 1},
      	 {(-2) . 1, (-3) . 2, (-4) . 2},
      	 {(-2) . 2, (-3) . 2, (-4) . 3}
	    }
	       },

   {3, 1, 'neq} . {
      'ep . {
	 {1 . 1},
      	 {2 . 1, 3 . 1, 4 . 1},
      	 {2 . 1, 3 . 2, 4 . 2},
      	 {2 . 2, 3 . 2, 4 . 3}
      	    }
	       },

   {3, -1, 'lessp} . {
      'slb . {
	 {(-1) . 1},
      	 {(-2) . 1, (-3) . 1, (-4) . 1},
      	 {(-2) . 2, (-3) . 2, (-4) . 3}
	    },
      'sub . {
	 {(-2) . 1, (-3) . 2, (-4) . 2}
	    }
	       },

   {3, nil, 'lessp} . {
      'slb . {
	 {2 . 1, 3 . 2, 4 . 2},
      	 {(-1) . 1},
      	 {(-2) . 1, (-3) . 1, (-4) . 1},
      	 {(-2) . 2, (-3) . 2, (-4) . 3}
	    },
      'sub . {
      	 {1 . 1},
      	 {2 . 1, 3 . 1, 4 . 1},
      	 {2 . 2, 3 . 2, 4 . 3},
      	 {(-2) . 1, (-3) . 2, (-4) . 2}
	    }
	       },

   {3, 1, 'lessp} . {
      'slb . {
	 {2 . 1, 3 . 2, 4 . 2}
	    },
      'sub . {
	 {1 . 1},
      	 {2 . 1, 3 . 1, 4 . 1},
      	 {2 . 2, 3 . 2, 4 . 3}
	    }
      	       },

   {3, -1, 'leq} . {
      'wlb . {
	 {(-1) . 1},
      	 {(-2) . 1, (-3) . 1, (-4) . 1},
      	 {(-2) . 2, (-3) . 2, (-4) . 3}
	    },
      'wub . {
	 {(-2) . 1, (-3) . 2, (-4) . 2}
	    }
	       },

   {3, nil, 'leq} . {
      'wlb . {
      	 {2 . 1, 3 . 2, 4 . 2},
      	 {(-1) . 1},
      	 {(-2) . 1, (-3) . 1, (-4) . 1},
      	 {(-2) . 2, (-3) . 2, (-4) . 3}
	    },
      'wub . {
	 {1 . 1},
      	 {2 . 1, 3 . 1, 4 . 1},
      	 {2 . 2, 3 . 2, 4 . 3},
      	 {(-2) . 1, (-3) . 2, (-4) . 2}
	    }
	       },

   {3, 1, 'leq} . {
      'wlb . {
	 {2 . 1, 3 . 2, 4 . 2}
	    },
      'wub . {
	 {1 . 1},
      	 {2 . 1, 3 . 1, 4 . 1},
      	 {2 . 2, 3 . 2, 4 . 3}
	    }
	       },

   {3, -1, 'geq} . {
      'wlb . {
	 {(-2) . 1, (-3) . 2, (-4) . 2}
      	    },
      'wub . {
	 {(-1) . 1},
      	 {(-2) . 1, (-3) . 1, (-4) . 1},
      	 {(-2) . 2, (-3) . 2, (-4) . 3}
	    }
	       },

   {3, nil, 'geq} . {
      'wlb . {
	 {1 . 1},
      	 {2 . 1, 3 . 1, 4 . 1},
      	 {2 . 2, 3 . 2, 4 . 3},
      	 {(-2) . 1, (-3) . 2, (-4) . 2}
   	    },
      'wub . {
	 {2 . 1, 3 . 2, 4 . 2},
      	 {(-1) . 1},
      	 {(-2) . 1, (-3) . 1, (-4) . 1},
      	 {(-2) . 2, (-3) . 2, (-4) . 3}
	    }
	       },

   {3, 1, 'geq} . {
      'wlb . {
	 {1 . 1},
      	 {2 . 1, 3 . 1, 4 . 1},
      	 {2 . 2, 3 . 2, 4 . 3}
      	    },
      'wub . {
	 {2 . 1, 3 . 2, 4 . 2}
	    }
	       },

   {3, -1, 'greaterp} . {
      'slb . {
	 {(-2) . 1, (-3) . 2, (-4) . 2}
      	    },
      'sub . {
	 {(-1) . 1},
	 {(-2) . 1, (-3) . 1, (-4) . 1},
      	 {(-2) . 2, (-3) . 2, (-4) . 3}
	    }
	       },

   {3, nil, 'greaterp} . {
      'slb . {
	 {1 . 1},
      	 {2 . 1, 3 . 1, 4 . 1},
      	 {2 . 2, 3 . 2, 4 . 3},
      	 {(-2) . 1, (-3) . 2, (-4) . 2}
   	    },
      'sub . {
	 {2 . 1, 3 . 2, 4 . 2},
      	 {(-1) . 1},
      	 {(-2) . 1, (-3) . 1, (-4) . 1},
      	 {(-2) . 2, (-3) . 2, (-4) . 3}
	    }
	       },

   {3, 1, 'greaterp} . {
      'slb . {
	 {1 . 1},
      	 {2 . 1, 3 . 1, 4 . 1},
      	 {2 . 2, 3 . 2, 4 . 3}
      	    },
      'sub . {
	 {2 . 1, 3 . 2, 4 . 2}
	    }
	       }
   		  };

%%% guard-fnalist %%%

guard!-fnalist!* := {
   % key: {ldeg f, rtl}
   % value: guard constructing function
   {1, '(-1)} . 'guard!-1!-1m,
   {1, '(1)} . 'guard!-1!-1,
   {1, '(-1 1)} . 'guard!-1!-2,

   {2, '(-2)} . 'guard!-2!-2m,
   {2, '(-1)} . 'guard!-2!-1m,
   {2, '(1)} . 'guard!-2!-1,
   {2, '(2)} . 'guard!-2!-2,
   {2, '(-2 -1)} . 'guard!-2!-3m,
   {2, '(1 2)} . 'guard!-2!-3,
   {2, '(-2 -1 1 2)} . 'guard!-2!-4,

   {3, '(-4)} . 'guard!-3!-4m,
   {3, '(-3)} . 'guard!-3!-3m,
   {3, '(-2)} . 'guard!-3!-2m,
   {3, '(-1)} . 'guard!-3!-1m,
   {3, '(1)} . 'guard!-3!-1,
   {3, '(2)} . 'guard!-3!-2,
   {3, '(3)} . 'guard!-3!-3,
   {3, '(4)} . 'guard!-3!-4,
   {3, '(-4 -3 -2)} . 'guard!-3!-5m,
   {3, '(2 3 4)} . 'guard!-3!-5
      };

%%% vsub-fnalist %%%

vsub!-fnalist!* := {
   % key: {ldeg f, rsl, ldeg g, op}
   % value: virtual substitution constructing function

   % 2, 1, equal
   {2, {1 . 1}, 1, 'equal} . 'vsub!-2!-1!-equal!-1,
   {2, {1 . 2}, 1, 'equal} . 'vsub!-2!-1!-equal!-2,
   {2, {2 . 1}, 1, 'equal} . 'vsub!-2!-1!-equal!-3,
   {2, {(-1) . 1}, 1, 'equal} . 'vsub!-2!-1!-equal!-1m,
   {2, {(-1) . 2}, 1, 'equal} . 'vsub!-2!-1!-equal!-2m,
   {2, {(-2) . 1}, 1, 'equal} . 'vsub!-2!-1!-equal!-3m,
   % 2, 1, equal, clustering
   {2, {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}, 1, 'equal} . 'vsub!-2!-1!-equal!-4,
   {2, {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}, 1, 'equal} . 'vsub!-2!-1!-equal!-5,
   {2, {1 . 1, 2 . 1}, 1, 'equal} . 'vsub!-2!-1!-equal!-1,
   {2, {1 . 2, 2 . 1}, 1, 'equal} . 'vsub!-2!-1!-equal!-2,
   {2, {(-1) . 1, (-2) . 1}, 1, 'equal} . 'vsub!-2!-1!-equal!-1m,
   {2, {(-1) . 2, (-2) . 1}, 1, 'equal} . 'vsub!-2!-1!-equal!-2m,

   % 2, 1, lessp
   {2, {1 . 1}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-1,
   {2, {1 . 2}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-2,
   {2, {2 . 1}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-3,
   {2, {(-1) . 1}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-1m,
   {2, {(-1) . 2}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-2m,
   {2, {(-2) . 1}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-3m,
   % 2, 1, lessp, clustering
   {2, {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-4,
   {2, {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-5,
   {2, {1 . 1, 2 . 1}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-1,
   {2, {1 . 2, 2 . 1}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-2,
   {2, {(-1) . 1, (-2) . 1}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-1m,
   {2, {(-1) . 2, (-2) . 1}, 1, 'lessp} . 'vsub!-2!-1!-lessp!-2m,

   % 2, 1, leq
   {2, {1 . 1}, 1, 'leq} . 'vsub!-2!-1!-leq!-1,
   {2, {1 . 2}, 1, 'leq} . 'vsub!-2!-1!-leq!-2,
   {2, {2 . 1}, 1, 'leq} . 'vsub!-2!-1!-leq!-3,
   {2, {(-1) . 1}, 1, 'leq} . 'vsub!-2!-1!-leq!-1m,
   {2, {(-1) . 2}, 1, 'leq} . 'vsub!-2!-1!-leq!-2m,
   {2, {(-2) . 1}, 1, 'leq} . 'vsub!-2!-1!-leq!-3m,
   % 2, 1, leq, clustering
   {2, {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}, 1, 'leq} . 'vsub!-2!-1!-leq!-4,
   {2, {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}, 1, 'leq} . 'vsub!-2!-1!-leq!-5,
   {2, {1 . 1, 2 . 1}, 1, 'leq} . 'vsub!-2!-1!-leq!-1,
   {2, {1 . 2, 2 . 1}, 1, 'leq} . 'vsub!-2!-1!-leq!-2,
   {2, {(-1) . 1, (-2) . 1}, 1, 'leq} . 'vsub!-2!-1!-leq!-1m,
   {2, {(-1) . 2, (-2) . 1}, 1, 'leq} . 'vsub!-2!-1!-leq!-2m,

   % 2, 1, neq
   {2, {1 . 1}, 1, 'neq} . 'vsub!-2!-1!-neq!-1,
   {2, {1 . 2}, 1, 'neq} . 'vsub!-2!-1!-neq!-2,
   {2, {2 . 1}, 1, 'neq} . 'vsub!-2!-1!-neq!-3,
   {2, {(-1) . 1}, 1, 'neq} . 'vsub!-2!-1!-neq!-1m,
   {2, {(-1) . 2}, 1, 'neq} . 'vsub!-2!-1!-neq!-2m,
   {2, {(-2) . 1}, 1, 'neq} . 'vsub!-2!-1!-neq!-3m,
   % 2, 1, neq, clustering
   {2, {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}, 1, 'neq} . 'vsub!-2!-1!-neq!-4,
   {2, {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}, 1, 'neq} . 'vsub!-2!-1!-neq!-5,
   {2, {1 . 1, 2 . 1}, 1, 'neq} . 'vsub!-2!-1!-neq!-1,
   {2, {1 . 2, 2 . 1}, 1, 'neq} . 'vsub!-2!-1!-neq!-2,
   {2, {(-1) . 1, (-2) . 1}, 1, 'neq} . 'vsub!-2!-1!-neq!-1m,
   {2, {(-1) . 2, (-2) . 1}, 1, 'neq} . 'vsub!-2!-1!-neq!-2m,

   % 2, 1, greaterp
   {2, {1 . 1}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-1,
   {2, {1 . 2}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-2,
   {2, {2 . 1}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-3,
   {2, {(-1) . 1}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-1m,
   {2, {(-1) . 2}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-2m,
   {2, {(-2) . 1}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-3m,
   % 2, 1, greaterp, clustering
   {2, {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-4,
   {2, {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-5,
   {2, {1 . 1, 2 . 1}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-1,
   {2, {1 . 2, 2 . 1}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-2,
   {2, {(-1) . 1, (-2) . 1}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-1m,
   {2, {(-1) . 2, (-2) . 1}, 1, 'greaterp} . 'vsub!-2!-1!-greaterp!-2m,

   % 2, 1, geq
   {2, {1 . 1}, 1, 'geq} . 'vsub!-2!-1!-geq!-1,
   {2, {1 . 2}, 1, 'geq} . 'vsub!-2!-1!-geq!-2,
   {2, {2 . 1}, 1, 'geq} . 'vsub!-2!-1!-geq!-3,
   {2, {(-1) . 1}, 1, 'geq} . 'vsub!-2!-1!-geq!-1m,
   {2, {(-1) . 2}, 1, 'geq} . 'vsub!-2!-1!-geq!-2m,
   {2, {(-2) . 1}, 1, 'geq} . 'vsub!-2!-1!-geq!-3m,
   % 2, 1, geq, clustering
   {2, {1 . 1, 2 . 1, (-1) . 2, (-2) . 1}, 1, 'geq} . 'vsub!-2!-1!-geq!-4,
   {2, {1 . 2, 2 . 1, (-1) . 1, (-2) . 1}, 1, 'geq} . 'vsub!-2!-1!-geq!-5,
   {2, {1 . 1, 2 . 1}, 1, 'geq} . 'vsub!-2!-1!-geq!-1,
   {2, {1 . 2, 2 . 1}, 1, 'geq} . 'vsub!-2!-1!-geq!-2,
   {2, {(-1) . 1, (-2) . 1}, 1, 'geq} . 'vsub!-2!-1!-geq!-1m,
   {2, {(-1) . 2, (-2) . 1}, 1, 'geq} . 'vsub!-2!-1!-geq!-2m,

   % 3, 1, equal
   {3, {1 . 1}, 1, 'equal} . 'vsub!-3!-1!-equal!-1,
   {3, {2 . 1}, 1, 'equal} . 'vsub!-3!-1!-equal!-2,
   {3, {2 . 2}, 1, 'equal} . 'vsub!-3!-1!-equal!-3,
   {3, {3 . 1}, 1, 'equal} . 'vsub!-3!-1!-equal!-4,
   {3, {3 . 2}, 1, 'equal} . 'vsub!-3!-1!-equal!-5,
   {3, {4 . 1}, 1, 'equal} . 'vsub!-3!-1!-equal!-6,
   {3, {4 . 2}, 1, 'equal} . 'vsub!-3!-1!-equal!-7,
   {3, {4 . 3}, 1, 'equal} . 'vsub!-3!-1!-equal!-8,
   {3, {(-1) . 1}, 1, 'equal} . 'vsub!-3!-1!-equal!-1m,
   {3, {(-2) . 1}, 1, 'equal} . 'vsub!-3!-1!-equal!-2m,
   {3, {(-2) . 2}, 1, 'equal} . 'vsub!-3!-1!-equal!-3m,
   {3, {(-3) . 1}, 1, 'equal} . 'vsub!-3!-1!-equal!-4m,
   {3, {(-3) . 2}, 1, 'equal} . 'vsub!-3!-1!-equal!-5m,
   {3, {(-4) . 1}, 1, 'equal} . 'vsub!-3!-1!-equal!-6m,
   {3, {(-4) . 2}, 1, 'equal} . 'vsub!-3!-1!-equal!-7m,
   {3, {(-4) . 3}, 1, 'equal} . 'vsub!-3!-1!-equal!-8m,
   % 3, 1, equal, clustering
   {3, {2 . 1, 3 . 1, 4 . 1}, 1, 'equal} . 'vsub!-3!-1!-equal!-9,
   {3, {2 . 1, 3 . 2, 4 . 2}, 1, 'equal} . 'vsub!-3!-1!-equal!-10,
   {3, {2 . 2, 3 . 2, 4 . 3}, 1, 'equal} . 'vsub!-3!-1!-equal!-11,
   {3, {(-2) . 1, (-3) . 1, (-4) . 1}, 1, 'equal} . 'vsub!-3!-1!-equal!-9m,
   {3, {(-2) . 1, (-3) . 2, (-4) . 2}, 1, 'equal} . 'vsub!-3!-1!-equal!-10m,
   {3, {(-2) . 2, (-3) . 2, (-4) . 3}, 1, 'equal} . 'vsub!-3!-1!-equal!-11m,

   % 3, 1, lessp
   {3, {1 . 1}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-1,
   {3, {2 . 1}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-2,
   {3, {2 . 2}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-3,
   {3, {3 . 1}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-4,
   {3, {3 . 2}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-5,
   {3, {4 . 1}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-6,
   {3, {4 . 2}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-7,
   {3, {4 . 3}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-8,
   {3, {(-1) . 1}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-1m,
   {3, {(-2) . 1}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-2m,
   {3, {(-2) . 2}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-3m,
   {3, {(-3) . 1}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-4m,
   {3, {(-3) . 2}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-5m,
   {3, {(-4) . 1}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-6m,
   {3, {(-4) . 2}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-7m,
   {3, {(-4) . 3}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-8m,
   % 3, 1, lessp, clustering
   {3, {2 . 1, 3 . 1, 4 . 1}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-9,
   {3, {2 . 1, 3 . 2, 4 . 2}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-10,
   {3, {2 . 2, 3 . 2, 4 . 3}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-11,
   {3, {(-2) . 1, (-3) . 1, (-4) . 1}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-9m,
   {3, {(-2) . 1, (-3) . 2, (-4) . 2}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-10m,
   {3, {(-2) . 2, (-3) . 2, (-4) . 3}, 1, 'lessp} . 'vsub!-3!-1!-lessp!-11m,

   % 3, 1, leq
   {3, {1 . 1}, 1, 'leq} . 'vsub!-3!-1!-leq!-1,
   {3, {2 . 1}, 1, 'leq} . 'vsub!-3!-1!-leq!-2,
   {3, {2 . 2}, 1, 'leq} . 'vsub!-3!-1!-leq!-3,
   {3, {3 . 1}, 1, 'leq} . 'vsub!-3!-1!-leq!-4,
   {3, {3 . 2}, 1, 'leq} . 'vsub!-3!-1!-leq!-5,
   {3, {4 . 1}, 1, 'leq} . 'vsub!-3!-1!-leq!-6,
   {3, {4 . 2}, 1, 'leq} . 'vsub!-3!-1!-leq!-7,
   {3, {4 . 3}, 1, 'leq} . 'vsub!-3!-1!-leq!-8,
   {3, {(-1) . 1}, 1, 'leq} . 'vsub!-3!-1!-leq!-1m,
   {3, {(-2) . 1}, 1, 'leq} . 'vsub!-3!-1!-leq!-2m,
   {3, {(-2) . 2}, 1, 'leq} . 'vsub!-3!-1!-leq!-3m,
   {3, {(-3) . 1}, 1, 'leq} . 'vsub!-3!-1!-leq!-4m,
   {3, {(-3) . 2}, 1, 'leq} . 'vsub!-3!-1!-leq!-5m,
   {3, {(-4) . 1}, 1, 'leq} . 'vsub!-3!-1!-leq!-6m,
   {3, {(-4) . 2}, 1, 'leq} . 'vsub!-3!-1!-leq!-7m,
   {3, {(-4) . 3}, 1, 'leq} . 'vsub!-3!-1!-leq!-8m,
   % 3, 1, leq, clustering
   {3, {2 . 1, 3 . 1, 4 . 1}, 1, 'leq} . 'vsub!-3!-1!-leq!-9,
   {3, {2 . 1, 3 . 2, 4 . 2}, 1, 'leq} . 'vsub!-3!-1!-leq!-10,
   {3, {2 . 2, 3 . 2, 4 . 3}, 1, 'leq} . 'vsub!-3!-1!-leq!-11,
   {3, {(-2) . 1, (-3) . 1, (-4) . 1}, 1, 'leq} . 'vsub!-3!-1!-leq!-9m,
   {3, {(-2) . 1, (-3) . 2, (-4) . 2}, 1, 'leq} . 'vsub!-3!-1!-leq!-10m,
   {3, {(-2) . 2, (-3) . 2, (-4) . 3}, 1, 'leq} . 'vsub!-3!-1!-leq!-11m,

   % 3, 1, neq
   {3, {1 . 1}, 1, 'neq} . 'vsub!-3!-1!-neq!-1,
   {3, {2 . 1}, 1, 'neq} . 'vsub!-3!-1!-neq!-2,
   {3, {2 . 2}, 1, 'neq} . 'vsub!-3!-1!-neq!-3,
   {3, {3 . 1}, 1, 'neq} . 'vsub!-3!-1!-neq!-4,
   {3, {3 . 2}, 1, 'neq} . 'vsub!-3!-1!-neq!-5,
   {3, {4 . 1}, 1, 'neq} . 'vsub!-3!-1!-neq!-6,
   {3, {4 . 2}, 1, 'neq} . 'vsub!-3!-1!-neq!-7,
   {3, {4 . 3}, 1, 'neq} . 'vsub!-3!-1!-neq!-8,
   {3, {(-1) . 1}, 1, 'neq} . 'vsub!-3!-1!-neq!-1m,
   {3, {(-2) . 1}, 1, 'neq} . 'vsub!-3!-1!-neq!-2m,
   {3, {(-2) . 2}, 1, 'neq} . 'vsub!-3!-1!-neq!-3m,
   {3, {(-3) . 1}, 1, 'neq} . 'vsub!-3!-1!-neq!-4m,
   {3, {(-3) . 2}, 1, 'neq} . 'vsub!-3!-1!-neq!-5m,
   {3, {(-4) . 1}, 1, 'neq} . 'vsub!-3!-1!-neq!-6m,
   {3, {(-4) . 2}, 1, 'neq} . 'vsub!-3!-1!-neq!-7m,
   {3, {(-4) . 3}, 1, 'neq} . 'vsub!-3!-1!-neq!-8m,
   % 3, 1, neq, clustering
   {3, {2 . 1, 3 . 1, 4 . 1}, 1, 'neq} . 'vsub!-3!-1!-neq!-9,
   {3, {2 . 1, 3 . 2, 4 . 2}, 1, 'neq} . 'vsub!-3!-1!-neq!-10,
   {3, {2 . 2, 3 . 2, 4 . 3}, 1, 'neq} . 'vsub!-3!-1!-neq!-11,
   {3, {(-2) . 1, (-3) . 1, (-4) . 1}, 1, 'neq} . 'vsub!-3!-1!-neq!-9m,
   {3, {(-2) . 1, (-3) . 2, (-4) . 2}, 1, 'neq} . 'vsub!-3!-1!-neq!-10m,
   {3, {(-2) . 2, (-3) . 2, (-4) . 3}, 1, 'neq} . 'vsub!-3!-1!-neq!-11m,

   % 3, 1, greaterp
   {3, {1 . 1}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-1,
   {3, {2 . 1}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-2,
   {3, {2 . 2}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-3,
   {3, {3 . 1}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-4,
   {3, {3 . 2}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-5,
   {3, {4 . 1}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-6,
   {3, {4 . 2}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-7,
   {3, {4 . 3}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-8,
   {3, {(-1) . 1}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-1m,
   {3, {(-2) . 1}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-2m,
   {3, {(-2) . 2}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-3m,
   {3, {(-3) . 1}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-4m,
   {3, {(-3) . 2}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-5m,
   {3, {(-4) . 1}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-6m,
   {3, {(-4) . 2}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-7m,
   {3, {(-4) . 3}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-8m,
   % 3, 1, greaterp, clustering
   {3, {2 . 1, 3 . 1, 4 . 1}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-9,
   {3, {2 . 1, 3 . 2, 4 . 2}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-10,
   {3, {2 . 2, 3 . 2, 4 . 3}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-11,
   {3, {(-2) . 1, (-3) . 1, (-4) . 1}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-9m,
   {3, {(-2) . 1, (-3) . 2, (-4) . 2}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-10m,
   {3, {(-2) . 2, (-3) . 2, (-4) . 3}, 1, 'greaterp} . 'vsub!-3!-1!-greaterp!-11m,

   % 3, 1, geq
   {3, {1 . 1}, 1, 'geq} . 'vsub!-3!-1!-geq!-1,
   {3, {2 . 1}, 1, 'geq} . 'vsub!-3!-1!-geq!-2,
   {3, {2 . 2}, 1, 'geq} . 'vsub!-3!-1!-geq!-3,
   {3, {3 . 1}, 1, 'geq} . 'vsub!-3!-1!-geq!-4,
   {3, {3 . 2}, 1, 'geq} . 'vsub!-3!-1!-geq!-5,
   {3, {4 . 1}, 1, 'geq} . 'vsub!-3!-1!-geq!-6,
   {3, {4 . 2}, 1, 'geq} . 'vsub!-3!-1!-geq!-7,
   {3, {4 . 3}, 1, 'geq} . 'vsub!-3!-1!-geq!-8,
   {3, {(-1) . 1}, 1, 'geq} . 'vsub!-3!-1!-geq!-1m,
   {3, {(-2) . 1}, 1, 'geq} . 'vsub!-3!-1!-geq!-2m,
   {3, {(-2) . 2}, 1, 'geq} . 'vsub!-3!-1!-geq!-3m,
   {3, {(-3) . 1}, 1, 'geq} . 'vsub!-3!-1!-geq!-4m,
   {3, {(-3) . 2}, 1, 'geq} . 'vsub!-3!-1!-geq!-5m,
   {3, {(-4) . 1}, 1, 'geq} . 'vsub!-3!-1!-geq!-6m,
   {3, {(-4) . 2}, 1, 'geq} . 'vsub!-3!-1!-geq!-7m,
   {3, {(-4) . 3}, 1, 'geq} . 'vsub!-3!-1!-geq!-8m,
   % 3, 1, geq, clustering
   {3, {2 . 1, 3 . 1, 4 . 1}, 1, 'geq} . 'vsub!-3!-1!-geq!-9,
   {3, {2 . 1, 3 . 2, 4 . 2}, 1, 'geq} . 'vsub!-3!-1!-geq!-10,
   {3, {2 . 2, 3 . 2, 4 . 3}, 1, 'geq} . 'vsub!-3!-1!-geq!-11,
   {3, {(-2) . 1, (-3) . 1, (-4) . 1}, 1, 'geq} . 'vsub!-3!-1!-geq!-9m,
   {3, {(-2) . 1, (-3) . 2, (-4) . 2}, 1, 'geq} . 'vsub!-3!-1!-geq!-10m,
   {3, {(-2) . 2, (-3) . 2, (-4) . 3}, 1, 'geq} . 'vsub!-3!-1!-geq!-11m,

   % 3, 2, equal
   {3, {1 . 1}, 2, 'equal} . 'vsub!-3!-2!-equal!-1,
   {3, {2 . 1}, 2, 'equal} . 'vsub!-3!-2!-equal!-2,
   {3, {2 . 2}, 2, 'equal} . 'vsub!-3!-2!-equal!-3,
   {3, {3 . 1}, 2, 'equal} . 'vsub!-3!-2!-equal!-4,
   {3, {3 . 2}, 2, 'equal} . 'vsub!-3!-2!-equal!-5,
   {3, {4 . 1}, 2, 'equal} . 'vsub!-3!-2!-equal!-6,
   {3, {4 . 2}, 2, 'equal} . 'vsub!-3!-2!-equal!-7,
   {3, {4 . 3}, 2, 'equal} . 'vsub!-3!-2!-equal!-8,
   {3, {(-1) . 1}, 2, 'equal} . 'vsub!-3!-2!-equal!-1m,
   {3, {(-2) . 1}, 2, 'equal} . 'vsub!-3!-2!-equal!-2m,
   {3, {(-2) . 2}, 2, 'equal} . 'vsub!-3!-2!-equal!-3m,
   {3, {(-3) . 1}, 2, 'equal} . 'vsub!-3!-2!-equal!-4m,
   {3, {(-3) . 2}, 2, 'equal} . 'vsub!-3!-2!-equal!-5m,
   {3, {(-4) . 1}, 2, 'equal} . 'vsub!-3!-2!-equal!-6m,
   {3, {(-4) . 2}, 2, 'equal} . 'vsub!-3!-2!-equal!-7m,
   {3, {(-4) . 3}, 2, 'equal} . 'vsub!-3!-2!-equal!-8m,
   % 3, 2, equal, clustering
   {3, {2 . 1, 3 . 1, 4 . 1}, 2, 'equal} . 'vsub!-3!-2!-equal!-9,
   {3, {2 . 1, 3 . 2, 4 . 2}, 2, 'equal} . 'vsub!-3!-2!-equal!-10,
   {3, {2 . 2, 3 . 2, 4 . 3}, 2, 'equal} . 'vsub!-3!-2!-equal!-11,
   {3, {(-2) . 1, (-3) . 1, (-4) . 1}, 2, 'equal} . 'vsub!-3!-2!-equal!-9m,
   {3, {(-2) . 1, (-3) . 2, (-4) . 2}, 2, 'equal} . 'vsub!-3!-2!-equal!-10m,
   {3, {(-2) . 2, (-3) . 2, (-4) . 3}, 2, 'equal} . 'vsub!-3!-2!-equal!-11m,

   % 3, 2, lessp
   {3, {1 . 1}, 2, 'lessp} . 'vsub!-3!-2!-lessp!-1,
   {3, {2 . 1}, 2, 'lessp} . 'vsub!-3!-2!-lessp!-2,
   {3, {2 . 2}, 2, 'lessp} . 'vsub!-3!-2!-lessp!-3,
   {3, {3 . 1}, 2, 'lessp} . 'vsub!-3!-2!-lessp!-4,
   {3, {3 . 2}, 2, 'lessp} . 'vsub!-3!-2!-lessp!-5,
   {3, {4 . 1}, 2, 'lessp} . 'vsub!-3!-2!-lessp!-6,
   {3, {4 . 2}, 2, 'lessp} . 'vsub!-3!-2!-lessp!-7,
   {3, {4 . 3}, 2, 'lessp} . 'vsub!-3!-2!-lessp!-8,
   {3, {(-1) . 1}, 2, 'lessp} . 'vsub!-3!-2!-lessp!-1m,
   {3, {(-2) . 1}, 2, 'lessp} . 'vsub!-3!-2!-lessp!-2m,
   {3, {(-2) . 2}, 2, 'lessp} . 'vsub!-3!-2!-lessp!-3m,
   {3, {(-3) . 1}, 2, 'lessp} . 'vsub!-3!-2!-lessp!-4m,
   {3, {(-3) . 2}, 2, 'lessp} . 'vsub!-3!-2!-lessp!-5m,
   {3, {(-4) . 1}, 2, 'lessp} . 'vsub!-3!-2!-lessp!-6m,
   {3, {(-4) . 2}, 2, 'lessp} . 'vsub!-3!-2!-lessp!-7m,
   {3, {(-4) . 3}, 2, 'lessp} . 'vsub!-3!-2!-lessp!-8m,
   % 3, 2, lessp, clustering
   {3, {2 . 1, 3 . 1, 4 . 1}, 2, 'lessp} . 'vsub!-3!-2!-lessp!-9,
   {3, {2 . 1, 3 . 2, 4 . 2}, 2, 'lessp} . 'vsub!-3!-2!-lessp!-10,
   {3, {2 . 2, 3 . 2, 4 . 3}, 2, 'lessp} . 'vsub!-3!-2!-lessp!-11,
   {3, {(-2) . 1, (-3) . 1, (-4) . 1}, 2, 'lessp} . 'vsub!-3!-2!-lessp!-9m,
   {3, {(-2) . 1, (-3) . 2, (-4) . 2}, 2, 'lessp} . 'vsub!-3!-2!-lessp!-10m,
   {3, {(-2) . 2, (-3) . 2, (-4) . 3}, 2, 'lessp} . 'vsub!-3!-2!-lessp!-11m,

   % 3, 2, leq
   {3, {1 . 1}, 2, 'leq} . 'vsub!-3!-2!-leq!-1,
   {3, {2 . 1}, 2, 'leq} . 'vsub!-3!-2!-leq!-2,
   {3, {2 . 2}, 2, 'leq} . 'vsub!-3!-2!-leq!-3,
   {3, {3 . 1}, 2, 'leq} . 'vsub!-3!-2!-leq!-4,
   {3, {3 . 2}, 2, 'leq} . 'vsub!-3!-2!-leq!-5,
   {3, {4 . 1}, 2, 'leq} . 'vsub!-3!-2!-leq!-6,
   {3, {4 . 2}, 2, 'leq} . 'vsub!-3!-2!-leq!-7,
   {3, {4 . 3}, 2, 'leq} . 'vsub!-3!-2!-leq!-8,
   {3, {(-1) . 1}, 2, 'leq} . 'vsub!-3!-2!-leq!-1m,
   {3, {(-2) . 1}, 2, 'leq} . 'vsub!-3!-2!-leq!-2m,
   {3, {(-2) . 2}, 2, 'leq} . 'vsub!-3!-2!-leq!-3m,
   {3, {(-3) . 1}, 2, 'leq} . 'vsub!-3!-2!-leq!-4m,
   {3, {(-3) . 2}, 2, 'leq} . 'vsub!-3!-2!-leq!-5m,
   {3, {(-4) . 1}, 2, 'leq} . 'vsub!-3!-2!-leq!-6m,
   {3, {(-4) . 2}, 2, 'leq} . 'vsub!-3!-2!-leq!-7m,
   {3, {(-4) . 3}, 2, 'leq} . 'vsub!-3!-2!-leq!-8m,
   % 3, 2, leq, clustering
   {3, {2 . 1, 3 . 1, 4 . 1}, 2, 'leq} . 'vsub!-3!-2!-leq!-9,
   {3, {2 . 1, 3 . 2, 4 . 2}, 2, 'leq} . 'vsub!-3!-2!-leq!-10,
   {3, {2 . 2, 3 . 2, 4 . 3}, 2, 'leq} . 'vsub!-3!-2!-leq!-11,
   {3, {(-2) . 1, (-3) . 1, (-4) . 1}, 2, 'leq} . 'vsub!-3!-2!-leq!-9m,
   {3, {(-2) . 1, (-3) . 2, (-4) . 2}, 2, 'leq} . 'vsub!-3!-2!-leq!-10m,
   {3, {(-2) . 2, (-3) . 2, (-4) . 3}, 2, 'leq} . 'vsub!-3!-2!-leq!-11m,

   % 3, 2, neq
   {3, {1 . 1}, 2, 'neq} . 'vsub!-3!-2!-neq!-1,
   {3, {2 . 1}, 2, 'neq} . 'vsub!-3!-2!-neq!-2,
   {3, {2 . 2}, 2, 'neq} . 'vsub!-3!-2!-neq!-3,
   {3, {3 . 1}, 2, 'neq} . 'vsub!-3!-2!-neq!-4,
   {3, {3 . 2}, 2, 'neq} . 'vsub!-3!-2!-neq!-5,
   {3, {4 . 1}, 2, 'neq} . 'vsub!-3!-2!-neq!-6,
   {3, {4 . 2}, 2, 'neq} . 'vsub!-3!-2!-neq!-7,
   {3, {4 . 3}, 2, 'neq} . 'vsub!-3!-2!-neq!-8,
   {3, {(-1) . 1}, 2, 'neq} . 'vsub!-3!-2!-neq!-1m,
   {3, {(-2) . 1}, 2, 'neq} . 'vsub!-3!-2!-neq!-2m,
   {3, {(-2) . 2}, 2, 'neq} . 'vsub!-3!-2!-neq!-3m,
   {3, {(-3) . 1}, 2, 'neq} . 'vsub!-3!-2!-neq!-4m,
   {3, {(-3) . 2}, 2, 'neq} . 'vsub!-3!-2!-neq!-5m,
   {3, {(-4) . 1}, 2, 'neq} . 'vsub!-3!-2!-neq!-6m,
   {3, {(-4) . 2}, 2, 'neq} . 'vsub!-3!-2!-neq!-7m,
   {3, {(-4) . 3}, 2, 'neq} . 'vsub!-3!-2!-neq!-8m,
   % 3, 2, neq, clustering
   {3, {2 . 1, 3 . 1, 4 . 1}, 2, 'neq} . 'vsub!-3!-2!-neq!-9,
   {3, {2 . 1, 3 . 2, 4 . 2}, 2, 'neq} . 'vsub!-3!-2!-neq!-10,
   {3, {2 . 2, 3 . 2, 4 . 3}, 2, 'neq} . 'vsub!-3!-2!-neq!-11,
   {3, {(-2) . 1, (-3) . 1, (-4) . 1}, 2, 'neq} . 'vsub!-3!-2!-neq!-9m,
   {3, {(-2) . 1, (-3) . 2, (-4) . 2}, 2, 'neq} . 'vsub!-3!-2!-neq!-10m,
   {3, {(-2) . 2, (-3) . 2, (-4) . 3}, 2, 'neq} . 'vsub!-3!-2!-neq!-11m,

   % 3, 2, greaterp
   {3, {1 . 1}, 2, 'greaterp} . 'vsub!-3!-2!-greaterp!-1,
   {3, {2 . 1}, 2, 'greaterp} . 'vsub!-3!-2!-greaterp!-2,
   {3, {2 . 2}, 2, 'greaterp} . 'vsub!-3!-2!-greaterp!-3,
   {3, {3 . 1}, 2, 'greaterp} . 'vsub!-3!-2!-greaterp!-4,
   {3, {3 . 2}, 2, 'greaterp} . 'vsub!-3!-2!-greaterp!-5,
   {3, {4 . 1}, 2, 'greaterp} . 'vsub!-3!-2!-greaterp!-6,
   {3, {4 . 2}, 2, 'greaterp} . 'vsub!-3!-2!-greaterp!-7,
   {3, {4 . 3}, 2, 'greaterp} . 'vsub!-3!-2!-greaterp!-8,
   {3, {(-1) . 1}, 2, 'greaterp} . 'vsub!-3!-2!-greaterp!-1m,
   {3, {(-2) . 1}, 2, 'greaterp} . 'vsub!-3!-2!-greaterp!-2m,
   {3, {(-2) . 2}, 2, 'greaterp} . 'vsub!-3!-2!-greaterp!-3m,
   {3, {(-3) . 1}, 2, 'greaterp} . 'vsub!-3!-2!-greaterp!-4m,
   {3, {(-3) . 2}, 2, 'greaterp} . 'vsub!-3!-2!-greaterp!-5m,
   {3, {(-4) . 1}, 2, 'greaterp} . 'vsub!-3!-2!-greaterp!-6m,
   {3, {(-4) . 2}, 2, 'greaterp} . 'vsub!-3!-2!-greaterp!-7m,
   {3, {(-4) . 3}, 2, 'greaterp} . 'vsub!-3!-2!-greaterp!-8m,
   % 3, 2, greaterp, clustering
   {3, {2 . 1, 3 . 1, 4 . 1}, 2, 'greaterp} . 'vsub!-3!-2!-greaterp!-9,
   {3, {2 . 1, 3 . 2, 4 . 2}, 2, 'greaterp} . 'vsub!-3!-2!-greaterp!-10,
   {3, {2 . 2, 3 . 2, 4 . 3}, 2, 'greaterp} . 'vsub!-3!-2!-greaterp!-11,
   {3, {(-2) . 1, (-3) . 1, (-4) . 1}, 2, 'greaterp} . 'vsub!-3!-2!-greaterp!-9m,
   {3, {(-2) . 1, (-3) . 2, (-4) . 2}, 2, 'greaterp} . 'vsub!-3!-2!-greaterp!-10m,
   {3, {(-2) . 2, (-3) . 2, (-4) . 3}, 2, 'greaterp} . 'vsub!-3!-2!-greaterp!-11m,

   % 3, 2, geq
   {3, {1 . 1}, 2, 'geq} . 'vsub!-3!-2!-geq!-1,
   {3, {2 . 1}, 2, 'geq} . 'vsub!-3!-2!-geq!-2,
   {3, {2 . 2}, 2, 'geq} . 'vsub!-3!-2!-geq!-3,
   {3, {3 . 1}, 2, 'geq} . 'vsub!-3!-2!-geq!-4,
   {3, {3 . 2}, 2, 'geq} . 'vsub!-3!-2!-geq!-5,
   {3, {4 . 1}, 2, 'geq} . 'vsub!-3!-2!-geq!-6,
   {3, {4 . 2}, 2, 'geq} . 'vsub!-3!-2!-geq!-7,
   {3, {4 . 3}, 2, 'geq} . 'vsub!-3!-2!-geq!-8,
   {3, {(-1) . 1}, 2, 'geq} . 'vsub!-3!-2!-geq!-1m,
   {3, {(-2) . 1}, 2, 'geq} . 'vsub!-3!-2!-geq!-2m,
   {3, {(-2) . 2}, 2, 'geq} . 'vsub!-3!-2!-geq!-3m,
   {3, {(-3) . 1}, 2, 'geq} . 'vsub!-3!-2!-geq!-4m,
   {3, {(-3) . 2}, 2, 'geq} . 'vsub!-3!-2!-geq!-5m,
   {3, {(-4) . 1}, 2, 'geq} . 'vsub!-3!-2!-geq!-6m,
   {3, {(-4) . 2}, 2, 'geq} . 'vsub!-3!-2!-geq!-7m,
   {3, {(-4) . 3}, 2, 'geq} . 'vsub!-3!-2!-geq!-8m,
   % 3, 2, geq, clustering
   {3, {2 . 1, 3 . 1, 4 . 1}, 2, 'geq} . 'vsub!-3!-2!-geq!-9,
   {3, {2 . 1, 3 . 2, 4 . 2}, 2, 'geq} . 'vsub!-3!-2!-geq!-10,
   {3, {2 . 2, 3 . 2, 4 . 3}, 2, 'geq} . 'vsub!-3!-2!-geq!-11,
   {3, {(-2) . 1, (-3) . 1, (-4) . 1}, 2, 'geq} . 'vsub!-3!-2!-geq!-9m,
   {3, {(-2) . 1, (-3) . 2, (-4) . 2}, 2, 'geq} . 'vsub!-3!-2!-geq!-10m,
   {3, {(-2) . 2, (-3) . 2, (-4) . 3}, 2, 'geq} . 'vsub!-3!-2!-geq!-11m
      };
