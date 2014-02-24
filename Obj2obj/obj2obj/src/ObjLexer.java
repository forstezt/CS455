// Generated from Obj.g4 by ANTLR 4.0
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class ObjLexer extends Lexer {
	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__3=1, T__2=2, T__1=3, T__0=4, COMMENT=5, NEWLINE=6, INT=7, FLOAT=8, 
		WHITESPACE=9;
	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] tokenNames = {
		"<INVALID>",
		"'v'", "'vt'", "'/'", "'f'", "COMMENT", "'\n'", "INT", "FLOAT", "WHITESPACE"
	};
	public static final String[] ruleNames = {
		"T__3", "T__2", "T__1", "T__0", "COMMENT", "NEWLINE", "INT", "FLOAT", 
		"WHITESPACE"
	};


	public ObjLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Obj.g4"; }

	@Override
	public String[] getTokenNames() { return tokenNames; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	@Override
	public void action(RuleContext _localctx, int ruleIndex, int actionIndex) {
		switch (ruleIndex) {
		case 4: COMMENT_action((RuleContext)_localctx, actionIndex); break;

		case 8: WHITESPACE_action((RuleContext)_localctx, actionIndex); break;
		}
	}
	private void WHITESPACE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 1: skip();  break;
		}
	}
	private void COMMENT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 0: skip();  break;
		}
	}

	public static final String _serializedATN =
		"\2\4\13G\b\1\4\2\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4"+
		"\t\t\t\4\n\t\n\3\2\3\2\3\3\3\3\3\3\3\4\3\4\3\5\3\5\3\6\3\6\7\6!\n\6\f"+
		"\6\16\6$\13\6\3\6\3\6\3\6\3\6\3\7\3\7\3\b\6\b-\n\b\r\b\16\b.\3\t\5\t\62"+
		"\n\t\3\t\6\t\65\n\t\r\t\16\t\66\3\t\3\t\6\t;\n\t\r\t\16\t<\5\t?\n\t\3"+
		"\n\6\nB\n\n\r\n\16\nC\3\n\3\n\3\"\13\3\3\1\5\4\1\7\5\1\t\6\1\13\7\2\r"+
		"\b\1\17\t\1\21\n\1\23\13\3\3\2\7\5%%qquu\3\62;\3\62;\3\62;\4\13\13\"\""+
		"M\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2"+
		"\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\3\25\3\2\2\2\5\27\3\2\2\2"+
		"\7\32\3\2\2\2\t\34\3\2\2\2\13\36\3\2\2\2\r)\3\2\2\2\17,\3\2\2\2\21\61"+
		"\3\2\2\2\23A\3\2\2\2\25\26\7x\2\2\26\4\3\2\2\2\27\30\7x\2\2\30\31\7v\2"+
		"\2\31\6\3\2\2\2\32\33\7\61\2\2\33\b\3\2\2\2\34\35\7h\2\2\35\n\3\2\2\2"+
		"\36\"\t\2\2\2\37!\13\2\2\2 \37\3\2\2\2!$\3\2\2\2\"#\3\2\2\2\" \3\2\2\2"+
		"#%\3\2\2\2$\"\3\2\2\2%&\5\r\7\2&\'\3\2\2\2\'(\b\6\2\2(\f\3\2\2\2)*\7\f"+
		"\2\2*\16\3\2\2\2+-\t\3\2\2,+\3\2\2\2-.\3\2\2\2.,\3\2\2\2./\3\2\2\2/\20"+
		"\3\2\2\2\60\62\7/\2\2\61\60\3\2\2\2\61\62\3\2\2\2\62\64\3\2\2\2\63\65"+
		"\t\4\2\2\64\63\3\2\2\2\65\66\3\2\2\2\66\64\3\2\2\2\66\67\3\2\2\2\67>\3"+
		"\2\2\28:\7\60\2\29;\t\5\2\2:9\3\2\2\2;<\3\2\2\2<:\3\2\2\2<=\3\2\2\2=?"+
		"\3\2\2\2>8\3\2\2\2>?\3\2\2\2?\22\3\2\2\2@B\t\6\2\2A@\3\2\2\2BC\3\2\2\2"+
		"CA\3\2\2\2CD\3\2\2\2DE\3\2\2\2EF\b\n\3\2F\24\3\2\2\2\n\2\".\61\66<>C";
	public static final ATN _ATN =
		ATNSimulator.deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
	}
}