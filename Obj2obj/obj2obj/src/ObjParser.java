// Generated from Obj.g4 by ANTLR 4.0
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class ObjParser extends Parser {
	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__3=1, T__2=2, T__1=3, T__0=4, COMMENT=5, NEWLINE=6, INT=7, FLOAT=8, 
		WHITESPACE=9;
	public static final String[] tokenNames = {
		"<INVALID>", "'v'", "'vt'", "'/'", "'f'", "COMMENT", "'\n'", "INT", "FLOAT", 
		"WHITESPACE"
	};
	public static final int
		RULE_file = 0, RULE_line = 1, RULE_entry = 2;
	public static final String[] ruleNames = {
		"file", "line", "entry"
	};

	@Override
	public String getGrammarFileName() { return "Obj.g4"; }

	@Override
	public String[] getTokenNames() { return tokenNames; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public ObjParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}
	public static class FileContext extends ParserRuleContext {
		public LineContext line(int i) {
			return getRuleContext(LineContext.class,i);
		}
		public List<LineContext> line() {
			return getRuleContexts(LineContext.class);
		}
		public TerminalNode EOF() { return getToken(ObjParser.EOF, 0); }
		public FileContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_file; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ObjListener ) ((ObjListener)listener).enterFile(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ObjListener ) ((ObjListener)listener).exitFile(this);
		}
	}

	public final FileContext file() throws RecognitionException {
		FileContext _localctx = new FileContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_file);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(9);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << 1) | (1L << 2) | (1L << 4) | (1L << COMMENT))) != 0)) {
				{
				{
				setState(6); line();
				}
				}
				setState(11);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(12); match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LineContext extends ParserRuleContext {
		public TerminalNode NEWLINE() { return getToken(ObjParser.NEWLINE, 0); }
		public EntryContext entry() {
			return getRuleContext(EntryContext.class,0);
		}
		public TerminalNode COMMENT() { return getToken(ObjParser.COMMENT, 0); }
		public LineContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_line; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ObjListener ) ((ObjListener)listener).enterLine(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ObjListener ) ((ObjListener)listener).exitLine(this);
		}
	}

	public final LineContext line() throws RecognitionException {
		LineContext _localctx = new LineContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_line);
		try {
			setState(18);
			switch (_input.LA(1)) {
			case 1:
			case 2:
			case 4:
				enterOuterAlt(_localctx, 1);
				{
				setState(14); entry();
				setState(15); match(NEWLINE);
				}
				break;
			case COMMENT:
				enterOuterAlt(_localctx, 2);
				{
				setState(17); match(COMMENT);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class EntryContext extends ParserRuleContext {
		public EntryContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_entry; }
	 
		public EntryContext() { }
		public void copyFrom(EntryContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class TextureCoordinateContext extends EntryContext {
		public List<TerminalNode> FLOAT() { return getTokens(ObjParser.FLOAT); }
		public TerminalNode FLOAT(int i) {
			return getToken(ObjParser.FLOAT, i);
		}
		public TextureCoordinateContext(EntryContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ObjListener ) ((ObjListener)listener).enterTextureCoordinate(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ObjListener ) ((ObjListener)listener).exitTextureCoordinate(this);
		}
	}
	public static class VertexContext extends EntryContext {
		public List<TerminalNode> FLOAT() { return getTokens(ObjParser.FLOAT); }
		public TerminalNode FLOAT(int i) {
			return getToken(ObjParser.FLOAT, i);
		}
		public VertexContext(EntryContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ObjListener ) ((ObjListener)listener).enterVertex(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ObjListener ) ((ObjListener)listener).exitVertex(this);
		}
	}
	public static class FaceContext extends EntryContext {
		public List<TerminalNode> INT() { return getTokens(ObjParser.INT); }
		public TerminalNode INT(int i) {
			return getToken(ObjParser.INT, i);
		}
		public FaceContext(EntryContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ObjListener ) ((ObjListener)listener).enterFace(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ObjListener ) ((ObjListener)listener).exitFace(this);
		}
	}

	public final EntryContext entry() throws RecognitionException {
		EntryContext _localctx = new EntryContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_entry);
		try {
			setState(37);
			switch (_input.LA(1)) {
			case 2:
				_localctx = new TextureCoordinateContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(20); match(2);
				setState(21); match(FLOAT);
				setState(22); match(FLOAT);
				}
				break;
			case 1:
				_localctx = new VertexContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(23); match(1);
				setState(24); match(FLOAT);
				setState(25); match(FLOAT);
				setState(26); match(FLOAT);
				}
				break;
			case 4:
				_localctx = new FaceContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(27); match(4);
				setState(28); match(INT);
				setState(29); match(3);
				setState(30); match(INT);
				setState(31); match(INT);
				setState(32); match(3);
				setState(33); match(INT);
				setState(34); match(INT);
				setState(35); match(3);
				setState(36); match(INT);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\2\3\13*\4\2\t\2\4\3\t\3\4\4\t\4\3\2\7\2\n\n\2\f\2\16\2\r\13\2\3\2\3\2"+
		"\3\3\3\3\3\3\3\3\5\3\25\n\3\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3"+
		"\4\3\4\3\4\3\4\3\4\3\4\3\4\5\4(\n\4\3\4\2\5\2\4\6\2\2*\2\13\3\2\2\2\4"+
		"\24\3\2\2\2\6\'\3\2\2\2\b\n\5\4\3\2\t\b\3\2\2\2\n\r\3\2\2\2\13\t\3\2\2"+
		"\2\13\f\3\2\2\2\f\16\3\2\2\2\r\13\3\2\2\2\16\17\7\1\2\2\17\3\3\2\2\2\20"+
		"\21\5\6\4\2\21\22\7\b\2\2\22\25\3\2\2\2\23\25\7\7\2\2\24\20\3\2\2\2\24"+
		"\23\3\2\2\2\25\5\3\2\2\2\26\27\7\4\2\2\27\30\7\n\2\2\30(\7\n\2\2\31\32"+
		"\7\3\2\2\32\33\7\n\2\2\33\34\7\n\2\2\34(\7\n\2\2\35\36\7\6\2\2\36\37\7"+
		"\t\2\2\37 \7\5\2\2 !\7\t\2\2!\"\7\t\2\2\"#\7\5\2\2#$\7\t\2\2$%\7\t\2\2"+
		"%&\7\5\2\2&(\7\t\2\2\'\26\3\2\2\2\'\31\3\2\2\2\'\35\3\2\2\2(\7\3\2\2\2"+
		"\5\13\24\'";
	public static final ATN _ATN =
		ATNSimulator.deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
	}
}