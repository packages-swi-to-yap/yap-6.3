// This file was automatically extracted from Gecode source files.
// It is subject to the same Copyright as the source files from which
// it is derived, and is distributed under the same Licensing conditions.
void abs(Home,IntVar,IntVar,IntConLevel=ICL_DEF);
void assign(Home,BoolVar,IntAssign,const ValBranchOptions&=ValBranchOptions::def);
void assign(Home,const BoolVarArgs&,IntAssign,const ValBranchOptions&=ValBranchOptions::def);
void assign(Home,const IntVarArgs&,IntAssign,const ValBranchOptions&=ValBranchOptions::def);
void assign(Home,const SetVarArgs&,SetAssign,const ValBranchOptions&=ValBranchOptions::def);
void assign(Home,IntVar,IntAssign,const ValBranchOptions&=ValBranchOptions::def);
void assign(Home,SetVar,SetAssign,const ValBranchOptions&=ValBranchOptions::def);
void atmostOne(Home,const SetVarArgs&,unsigned int);
void binpacking(Home,const IntVarArgs&,const IntVarArgs&,const IntArgs&,IntConLevel=ICL_DEF);
void branch(Home,BoolVar,IntValBranch,const ValBranchOptions&=ValBranchOptions::def);
void branch(Home,const BoolVarArgs&,const TieBreakVarBranch<IntVarBranch>&,IntValBranch,const TieBreakVarBranchOptions&=TieBreakVarBranchOptions::def,const ValBranchOptions&=ValBranchOptions::def);
void branch(Home,const BoolVarArgs&,IntVarBranch,IntValBranch,const VarBranchOptions&=VarBranchOptions::def,const ValBranchOptions&=ValBranchOptions::def);
void branch(Home,const IntVarArgs&,const TieBreakVarBranch<IntVarBranch>&,IntValBranch,const TieBreakVarBranchOptions&=TieBreakVarBranchOptions::def,const ValBranchOptions&=ValBranchOptions::def);
void branch(Home,const IntVarArgs&,IntVarBranch,IntValBranch,const VarBranchOptions&=VarBranchOptions::def,const ValBranchOptions&=ValBranchOptions::def);
void branch(Home,const SetVarArgs&,const TieBreakVarBranch<SetVarBranch>&,SetValBranch,const TieBreakVarBranchOptions&=TieBreakVarBranchOptions::def,const ValBranchOptions&=ValBranchOptions::def);
void branch(Home,const SetVarArgs&,SetVarBranch,SetValBranch,const VarBranchOptions&=VarBranchOptions::def,const ValBranchOptions&=ValBranchOptions::def);
void branch(Home,IntVar,IntValBranch,const ValBranchOptions&=ValBranchOptions::def);
void branch(Home,SetVar,SetValBranch,const ValBranchOptions&=ValBranchOptions::def);
void cardinality(Home,SetVar,IntVar);
void cardinality(Home,SetVar,unsigned int,unsigned int);
void channel(Home,BoolVar,IntVar,IntConLevel=ICL_DEF);
void channel(Home,const BoolVarArgs&,IntVar,int=0,IntConLevel=ICL_DEF);
void channel(Home,const BoolVarArgs&,SetVar);
void channel(Home,const IntVarArgs&,const IntVarArgs&,IntConLevel=ICL_DEF);
void channel(Home,const IntVarArgs&,const SetVarArgs&);
void channel(Home,const IntVarArgs&,int,const IntVarArgs&,int,IntConLevel=ICL_DEF);
void channel(Home,const SetVarArgs&,const SetVarArgs&);
void channel(Home,IntVar,BoolVar,IntConLevel=ICL_DEF);
void channelSorted(Home,const IntVarArgs&,SetVar);
void circuit(Home,const IntArgs&,const IntVarArgs&,const IntVarArgs&,IntVar,IntConLevel=ICL_DEF);
void circuit(Home,const IntArgs&,const IntVarArgs&,IntVar,IntConLevel=ICL_DEF);
void circuit(Home,const IntArgs&,int,const IntVarArgs&,const IntVarArgs&,IntVar,IntConLevel=ICL_DEF);
void circuit(Home,const IntArgs&,int,const IntVarArgs&,IntVar,IntConLevel=ICL_DEF);
void circuit(Home,const IntVarArgs&,IntConLevel=ICL_DEF);
void circuit(Home,int,const IntVarArgs&,IntConLevel=ICL_DEF);
void clause(Home,BoolOpType,const BoolVarArgs&,const BoolVarArgs&,BoolVar,IntConLevel=ICL_DEF);
void clause(Home,BoolOpType,const BoolVarArgs&,const BoolVarArgs&,int,IntConLevel=ICL_DEF);
void convex(Home,SetVar);
void convex(Home,SetVar,SetVar);
void count(Home,const IntVarArgs&,const IntArgs&,IntRelType,int,IntConLevel=ICL_DEF);
void count(Home,const IntVarArgs&,const IntArgs&,IntRelType,IntVar,IntConLevel=ICL_DEF);
void count(Home,const IntVarArgs&,const IntSetArgs&,const IntArgs&,IntConLevel=ICL_DEF);
void count(Home,const IntVarArgs&,const IntSetArgs&,IntConLevel=ICL_DEF);
void count(Home,const IntVarArgs&,const IntSet&,const IntArgs&,IntConLevel=ICL_DEF);
void count(Home,const IntVarArgs&,const IntSet&,IntRelType,int,IntConLevel=ICL_DEF);
void count(Home,const IntVarArgs&,const IntSet&,IntRelType,IntVar,IntConLevel=ICL_DEF);
void count(Home,const IntVarArgs&,const IntVarArgs&,const IntArgs&,IntConLevel=ICL_DEF);
void count(Home,const IntVarArgs&,const IntVarArgs&,IntConLevel=ICL_DEF);
void count(Home,const IntVarArgs&,int,IntRelType,int,IntConLevel=ICL_DEF);
void count(Home,const IntVarArgs&,int,IntRelType,IntVar,IntConLevel=ICL_DEF);
void count(Home,const IntVarArgs&,IntVar,IntRelType,int,IntConLevel=ICL_DEF);
void count(Home,const IntVarArgs&,IntVar,IntRelType,IntVar,IntConLevel=ICL_DEF);
void cumulative(Home,int,const IntVarArgs&,const IntArgs&,const IntArgs&,const BoolVarArgs&,IntConLevel=ICL_DEF);
void cumulative(Home,int,const IntVarArgs&,const IntArgs&,const IntArgs&,IntConLevel=ICL_DEF);
void cumulative(Home,int,const IntVarArgs&,const IntVarArgs&,const IntVarArgs&,const IntArgs&,const BoolVarArgs&,IntConLevel=ICL_DEF);
void cumulative(Home,int,const IntVarArgs&,const IntVarArgs&,const IntVarArgs&,const IntArgs&,IntConLevel=ICL_DEF);
void cumulative(Home,int,const TaskTypeArgs&,const IntVarArgs&,const IntArgs&,const IntArgs&,const BoolVarArgs&,IntConLevel=ICL_DEF);
void cumulative(Home,int,const TaskTypeArgs&,const IntVarArgs&,const IntArgs&,const IntArgs&,IntConLevel=ICL_DEF);
void cumulative(Home,IntVar,const IntVarArgs&,const IntArgs&,const IntArgs&,const BoolVarArgs&,IntConLevel=ICL_DEF);
void cumulative(Home,IntVar,const IntVarArgs&,const IntArgs&,const IntArgs&,IntConLevel=ICL_DEF);
void cumulative(Home,IntVar,const IntVarArgs&,const IntVarArgs&,const IntVarArgs&,const IntArgs&,const BoolVarArgs&,IntConLevel=ICL_DEF);
void cumulative(Home,IntVar,const IntVarArgs&,const IntVarArgs&,const IntVarArgs&,const IntArgs&,IntConLevel=ICL_DEF);
void cumulative(Home,IntVar,const TaskTypeArgs&,const IntVarArgs&,const IntArgs&,const IntArgs&,const BoolVarArgs&,IntConLevel=ICL_DEF);
void cumulative(Home,IntVar,const TaskTypeArgs&,const IntVarArgs&,const IntArgs&,const IntArgs&,IntConLevel=ICL_DEF);
void cumulatives(Home,const IntArgs&,const IntVarArgs&,const IntArgs&,const IntVarArgs&,const IntArgs&,const IntArgs&,bool,IntConLevel=ICL_DEF);
void cumulatives(Home,const IntArgs&,const IntVarArgs&,const IntArgs&,const IntVarArgs&,const IntVarArgs&,const IntArgs&,bool,IntConLevel=ICL_DEF);
void cumulatives(Home,const IntArgs&,const IntVarArgs&,const IntVarArgs&,const IntVarArgs&,const IntArgs&,const IntArgs&,bool,IntConLevel=ICL_DEF);
void cumulatives(Home,const IntArgs&,const IntVarArgs&,const IntVarArgs&,const IntVarArgs&,const IntVarArgs&,const IntArgs&,bool,IntConLevel=ICL_DEF);
void cumulatives(Home,const IntVarArgs&,const IntVarArgs&,const IntArgs&,const IntVarArgs&,const IntArgs&,const IntArgs&,bool,IntConLevel=ICL_DEF);
void cumulatives(Home,const IntVarArgs&,const IntVarArgs&,const IntArgs&,const IntVarArgs&,const IntVarArgs&,const IntArgs&,bool,IntConLevel=ICL_DEF);
void cumulatives(Home,const IntVarArgs&,const IntVarArgs&,const IntVarArgs&,const IntVarArgs&,const IntArgs&,const IntArgs&,bool,IntConLevel=ICL_DEF);
void cumulatives(Home,const IntVarArgs&,const IntVarArgs&,const IntVarArgs&,const IntVarArgs&,const IntVarArgs&,const IntArgs&,bool,IntConLevel=ICL_DEF);
void distinct(Home,const IntArgs&,const IntVarArgs&,IntConLevel=ICL_DEF);
void distinct(Home,const IntVarArgs&,IntConLevel=ICL_DEF);
void div(Home,IntVar,IntVar,IntVar,IntConLevel=ICL_DEF);
void divmod(Home,IntVar,IntVar,IntVar,IntVar,IntConLevel=ICL_DEF);
void dom(Home,const IntVarArgs&,const IntSet&,IntConLevel=ICL_DEF);
void dom(Home,const IntVarArgs&,int,IntConLevel=ICL_DEF);
void dom(Home,const IntVarArgs&,int,int,IntConLevel=ICL_DEF);
void dom(Home,IntVar,const IntSet&,IntConLevel=ICL_DEF);
void dom(Home,IntVar,const IntSet&,Reify,IntConLevel=ICL_DEF);
void dom(Home,IntVar,int,IntConLevel=ICL_DEF);
void dom(Home,IntVar,int,int,IntConLevel=ICL_DEF);
void dom(Home,IntVar,int,int,Reify,IntConLevel=ICL_DEF);
void dom(Home,IntVar,int,Reify,IntConLevel=ICL_DEF);
void dom(Home,SetVar,SetRelType,const IntSet&);
void dom(Home,SetVar,SetRelType,const IntSet&,BoolVar);
void dom(Home,SetVar,SetRelType,int);
void dom(Home,SetVar,SetRelType,int,BoolVar);
void dom(Home,SetVar,SetRelType,int,int);
void dom(Home,SetVar,SetRelType,int,int,BoolVar);
void element(Home,const BoolVarArgs&,IntVar,BoolVar,IntConLevel=ICL_DEF);
void element(Home,const BoolVarArgs&,IntVar,int,IntConLevel=ICL_DEF);
void element(Home,const BoolVarArgs&,IntVar,int,IntVar,int,BoolVar,IntConLevel=ICL_DEF);
void element(Home,const IntSetArgs&,IntVar,int,IntVar,int,SetVar);
void element(Home,const IntSetArgs&,IntVar,SetVar);
void element(Home,const IntVarArgs&,IntVar,int,IntConLevel=ICL_DEF);
void element(Home,const IntVarArgs&,IntVar,int,IntVar,int,IntVar,IntConLevel=ICL_DEF);
void element(Home,const IntVarArgs&,IntVar,IntVar,IntConLevel=ICL_DEF);
void element(Home,const SetVarArgs&,IntVar,int,IntVar,int,SetVar);
void element(Home,const SetVarArgs&,IntVar,SetVar);
void element(Home,IntSharedArray,IntVar,BoolVar,IntConLevel=ICL_DEF);
void element(Home,IntSharedArray,IntVar,int,IntConLevel=ICL_DEF);
void element(Home,IntSharedArray,IntVar,int,IntVar,int,BoolVar,IntConLevel=ICL_DEF);
void element(Home,IntSharedArray,IntVar,int,IntVar,int,IntVar,IntConLevel=ICL_DEF);
void element(Home,IntSharedArray,IntVar,IntVar,IntConLevel=ICL_DEF);
void element(Home,SetOpType,const IntArgs&,SetVar,SetVar,const IntSet&=IntSet(Set::Limits::min,Set::Limits::max));
void element(Home,SetOpType,const IntSetArgs&,SetVar,SetVar,const IntSet&=IntSet(Set::Limits::min,Set::Limits::max));
void element(Home,SetOpType,const IntVarArgs&,SetVar,SetVar,const IntSet&=IntSet(Set::Limits::min,Set::Limits::max));
void element(Home,SetOpType,const SetVarArgs&,SetVar,SetVar,const IntSet&=IntSet(Set::Limits::min,Set::Limits::max));
void extensional(Home,const BoolVarArgs&,const TupleSet&,ExtensionalPropKind=EPK_DEF,IntConLevel=ICL_DEF);
void extensional(Home,const BoolVarArgs&,DFA,IntConLevel=ICL_DEF);
void extensional(Home,const IntVarArgs&,const TupleSet&,ExtensionalPropKind=EPK_DEF,IntConLevel=ICL_DEF);
void extensional(Home,const IntVarArgs&,DFA,IntConLevel=ICL_DEF);
void linear(Home,const BoolVarArgs&,IntRelType,int,IntConLevel=ICL_DEF);
void linear(Home,const BoolVarArgs&,IntRelType,int,Reify,IntConLevel=ICL_DEF);
void linear(Home,const BoolVarArgs&,IntRelType,IntVar,IntConLevel=ICL_DEF);
void linear(Home,const BoolVarArgs&,IntRelType,IntVar,Reify,IntConLevel=ICL_DEF);
void linear(Home,const IntArgs&,const BoolVarArgs&,IntRelType,int,IntConLevel=ICL_DEF);
void linear(Home,const IntArgs&,const BoolVarArgs&,IntRelType,int,Reify,IntConLevel=ICL_DEF);
void linear(Home,const IntArgs&,const BoolVarArgs&,IntRelType,IntVar,IntConLevel=ICL_DEF);
void linear(Home,const IntArgs&,const BoolVarArgs&,IntRelType,IntVar,Reify,IntConLevel=ICL_DEF);
void linear(Home,const IntArgs&,const IntVarArgs&,IntRelType,int,IntConLevel=ICL_DEF);
void linear(Home,const IntArgs&,const IntVarArgs&,IntRelType,int,Reify,IntConLevel=ICL_DEF);
void linear(Home,const IntArgs&,const IntVarArgs&,IntRelType,IntVar,IntConLevel=ICL_DEF);
void linear(Home,const IntArgs&,const IntVarArgs&,IntRelType,IntVar,Reify,IntConLevel=ICL_DEF);
void linear(Home,const IntVarArgs&,IntRelType,int,IntConLevel=ICL_DEF);
void linear(Home,const IntVarArgs&,IntRelType,int,Reify,IntConLevel=ICL_DEF);
void linear(Home,const IntVarArgs&,IntRelType,IntVar,IntConLevel=ICL_DEF);
void linear(Home,const IntVarArgs&,IntRelType,IntVar,Reify,IntConLevel=ICL_DEF);
void max(Home,const IntVarArgs&,IntVar,IntConLevel=ICL_DEF);
void max(Home,IntVar,IntVar,IntVar,IntConLevel=ICL_DEF);
void max(Home,SetVar,IntVar);
void max(Home,SetVar,IntVar,BoolVar);
void member(Home,const BoolVarArgs&,BoolVar,IntConLevel=ICL_DEF);
void member(Home,const BoolVarArgs&,BoolVar,Reify,IntConLevel=ICL_DEF);
void member(Home,const IntVarArgs&,IntVar,IntConLevel=ICL_DEF);
void member(Home,const IntVarArgs&,IntVar,Reify,IntConLevel=ICL_DEF);
void min(Home,const IntVarArgs&,IntVar,IntConLevel=ICL_DEF);
void min(Home,IntVar,IntVar,IntVar,IntConLevel=ICL_DEF);
void min(Home,SetVar,IntVar);
void min(Home,SetVar,IntVar,BoolVar);
void mod(Home,IntVar,IntVar,IntVar,IntConLevel=ICL_DEF);
void mult(Home,IntVar,IntVar,IntVar,IntConLevel=ICL_DEF);
void nooverlap(Home,const IntVarArgs&,const IntArgs&,const IntVarArgs&,const IntArgs&,const BoolVarArgs&,IntConLevel=ICL_DEF);
void nooverlap(Home,const IntVarArgs&,const IntArgs&,const IntVarArgs&,const IntArgs&,IntConLevel=ICL_DEF);
void nooverlap(Home,const IntVarArgs&,const IntVarArgs&,const IntVarArgs&,const IntVarArgs&,const IntVarArgs&,const IntVarArgs&,const BoolVarArgs&,IntConLevel=ICL_DEF);
void nooverlap(Home,const IntVarArgs&,const IntVarArgs&,const IntVarArgs&,const IntVarArgs&,const IntVarArgs&,const IntVarArgs&,IntConLevel=ICL_DEF);
void notMax(Home,SetVar,IntVar);
void notMin(Home,SetVar,IntVar);
void nvalues(Home,const BoolVarArgs&,IntRelType,int,IntConLevel=ICL_DEF);
void nvalues(Home,const BoolVarArgs&,IntRelType,IntVar,IntConLevel=ICL_DEF);
void nvalues(Home,const IntVarArgs&,IntRelType,int,IntConLevel=ICL_DEF);
void nvalues(Home,const IntVarArgs&,IntRelType,IntVar,IntConLevel=ICL_DEF);
void path(Home,const IntArgs&,const IntVarArgs&,IntVar,IntVar,const IntVarArgs&,IntVar,IntConLevel=ICL_DEF);
void path(Home,const IntArgs&,const IntVarArgs&,IntVar,IntVar,IntVar,IntConLevel=ICL_DEF);
void path(Home,const IntArgs&,int,const IntVarArgs&,IntVar,IntVar,const IntVarArgs&,IntVar,IntConLevel=ICL_DEF);
void path(Home,const IntArgs&,int,const IntVarArgs&,IntVar,IntVar,IntVar,IntConLevel=ICL_DEF);
void path(Home,const IntVarArgs&,IntVar,IntVar,IntConLevel=ICL_DEF);
void path(Home,int,const IntVarArgs&,IntVar,IntVar,IntConLevel=ICL_DEF);
void precede(Home,const IntVarArgs&,const IntArgs&,IntConLevel=ICL_DEF);
void precede(Home,const IntVarArgs&,int,int,IntConLevel=ICL_DEF);
void precede(Home,const SetVarArgs&,const IntArgs&);
void precede(Home,const SetVarArgs&,int,int);
void rel(Home,BoolOpType,const BoolVarArgs&,BoolVar,IntConLevel=ICL_DEF);
void rel(Home,BoolOpType,const BoolVarArgs&,int,IntConLevel=ICL_DEF);
void rel(Home,BoolVar,BoolOpType,BoolVar,BoolVar,IntConLevel=ICL_DEF);
void rel(Home,BoolVar,BoolOpType,BoolVar,int,IntConLevel=ICL_DEF);
void rel(Home,BoolVar,IntRelType,BoolVar,IntConLevel=ICL_DEF);
void rel(Home,BoolVar,IntRelType,BoolVar,Reify,IntConLevel=ICL_DEF);
void rel(Home,BoolVar,IntRelType,int,IntConLevel=ICL_DEF);
void rel(Home,BoolVar,IntRelType,int,Reify,IntConLevel=ICL_DEF);
void rel(Home,const BoolVarArgs&,IntRelType,BoolVar,IntConLevel=ICL_DEF);
void rel(Home,const BoolVarArgs&,IntRelType,const BoolVarArgs&,IntConLevel=ICL_DEF);
void rel(Home,const BoolVarArgs&,IntRelType,IntConLevel=ICL_DEF);
void rel(Home,const BoolVarArgs&,IntRelType,int,IntConLevel=ICL_DEF);
void rel(Home,const IntSet&,SetOpType,SetVar,SetRelType,const IntSet&);
void rel(Home,const IntSet&,SetOpType,SetVar,SetRelType,SetVar);
void rel(Home,const IntVarArgs&,IntRelType,const IntVarArgs&,IntConLevel=ICL_DEF);
void rel(Home,const IntVarArgs&,IntRelType,IntConLevel=ICL_DEF);
void rel(Home,const IntVarArgs&,IntRelType,int,IntConLevel=ICL_DEF);
void rel(Home,const IntVarArgs&,IntRelType,IntVar,IntConLevel=ICL_DEF);
void rel(Home,IntVar,IntRelType,int,IntConLevel=ICL_DEF);
void rel(Home,IntVar,IntRelType,int,Reify,IntConLevel=ICL_DEF);
void rel(Home,IntVar,IntRelType,IntVar,IntConLevel=ICL_DEF);
void rel(Home,IntVar,IntRelType,IntVar,Reify,IntConLevel=ICL_DEF);
void rel(Home,IntVar,IntRelType,SetVar);
void rel(Home,IntVar,SetRelType,SetVar);
void rel(Home,IntVar,SetRelType,SetVar,BoolVar);
void rel(Home,SetOpType,const IntVarArgs&,const IntSet&,SetVar);
void rel(Home,SetOpType,const IntVarArgs&,SetVar);
void rel(Home,SetOpType,const SetVarArgs&,const IntSet&,SetVar);
void rel(Home,SetOpType,const SetVarArgs&,SetVar);
void rel(Home,SetVar,IntRelType,IntVar);
void rel(Home,SetVar,SetOpType,const IntSet&,SetRelType,const IntSet&);
void rel(Home,SetVar,SetOpType,const IntSet&,SetRelType,SetVar);
void rel(Home,SetVar,SetOpType,SetVar,SetRelType,const IntSet&);
void rel(Home,SetVar,SetOpType,SetVar,SetRelType,SetVar);
void rel(Home,SetVar,SetRelType,IntVar);
void rel(Home,SetVar,SetRelType,IntVar,BoolVar);
void rel(Home,SetVar,SetRelType,SetVar);
void rel(Home,SetVar,SetRelType,SetVar,BoolVar);
void sequence(Home,const BoolVarArgs&,const IntSet&,int,int,int,IntConLevel=ICL_DEF);
void sequence(Home,const IntVarArgs&,const IntSet&,int,int,int,IntConLevel=ICL_DEF);
void sequence(Home,const SetVarArgs&);
void sequence(Home,const SetVarArgs&,SetVar);
void sorted(Home,const IntVarArgs&,const IntVarArgs&,const IntVarArgs&,IntConLevel=ICL_DEF);
void sorted(Home,const IntVarArgs&,const IntVarArgs&,IntConLevel=ICL_DEF);
void sqr(Home,IntVar,IntVar,IntConLevel=ICL_DEF);
void sqrt(Home,IntVar,IntVar,IntConLevel=ICL_DEF);
void unary(Home,const IntVarArgs&,const IntArgs&,const BoolVarArgs&,IntConLevel=ICL_DEF);
void unary(Home,const IntVarArgs&,const IntArgs&,IntConLevel=ICL_DEF);
void unary(Home,const IntVarArgs&,const IntVarArgs&,const IntVarArgs&,const BoolVarArgs&,IntConLevel=ICL_DEF);
void unary(Home,const IntVarArgs&,const IntVarArgs&,const IntVarArgs&,IntConLevel=ICL_DEF);
void unary(Home,const TaskTypeArgs&,const IntVarArgs&,const IntArgs&,const BoolVarArgs&,IntConLevel=ICL_DEF);
void unary(Home,const TaskTypeArgs&,const IntVarArgs&,const IntArgs&,IntConLevel=ICL_DEF);
void unshare(Home,BoolVarArgs&,IntConLevel=ICL_DEF);
void unshare(Home,IntVarArgs&,IntConLevel=ICL_DEF);
void weights(Home,IntSharedArray,IntSharedArray,SetVar,IntVar);