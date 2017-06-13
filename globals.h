/**
 * @file
 * Hundreds of global variables to back the user variables
 *
 * @authors
 * Copyright (C) 1996-2002,2010,2016 Michael R. Elkins <me@mutt.org>
 *
 * @copyright
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 2 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _MUTT_GLOBALS_H
#define _MUTT_GLOBALS_H

#include <signal.h>
#include "lib.h"
#include "where.h"
#include "mutt_regex.h"

#ifdef MAIN_C
/* so that global vars get included */
#include "git_ver.h"
#include "mx.h"
#include "ncrypt/ncrypt.h"
#include "sort.h"
#endif /* MAIN_C */

WHERE void (*mutt_error)(const char *, ...);
WHERE void (*mutt_message)(const char *, ...);

WHERE struct Context *Context;

WHERE char Errorbuf[STRING];
WHERE char AttachmentMarker[STRING];

WHERE struct Address *EnvFrom;
WHERE struct Address *From;

WHERE char *AliasFile;
WHERE char *AliasFmt;
WHERE char *AssumedCharset;
WHERE char *AttachSep;
WHERE char *Attribution;
WHERE char *AttributionLocale;
WHERE char *AttachCharset;
WHERE char *AttachFormat;
WHERE struct Regex AttachKeyword;
WHERE char *Charset;
WHERE char *ComposeFormat;
WHERE char *ConfigCharset;
WHERE char *ContentType;
WHERE char *DefaultHook;
WHERE char *DateFmt;
WHERE char *DisplayFilter;
WHERE char *DsnNotify;
WHERE char *DsnReturn;
WHERE char *Editor;
WHERE char *EmptySubject;
WHERE char *EscChar;
WHERE char *FolderFormat;
WHERE char *ForwardAttrIntro;
WHERE char *ForwardAttrTrailer;
WHERE char *ForwFmt;
WHERE char *Fqdn;
WHERE struct MbCharTable *Fromchars;
WHERE char *HdrFmt;
WHERE char *HistFile;
WHERE char *Homedir;
WHERE char *Hostname;
#ifdef USE_IMAP
WHERE char *ImapAuthenticators INITVAL(NULL);
WHERE char *ImapDelimChars INITVAL(NULL);
WHERE char *ImapHeaders;
WHERE char *ImapLogin INITVAL(NULL);
WHERE char *ImapPass INITVAL(NULL);
WHERE char *ImapUser INITVAL(NULL);
#endif
WHERE char *Inbox;
WHERE char *Ispell;
WHERE char *MailcapPath;
WHERE char *Maildir;
#if defined(USE_IMAP) || defined(USE_POP) || defined(USE_NNTP)
WHERE char *MessageCachedir;
#endif
#ifdef USE_HCACHE
WHERE char *HeaderCache;
WHERE char *HeaderCacheBackend;
#if defined(HAVE_GDBM) || defined(HAVE_BDB)
WHERE char *HeaderCachePageSize;
#endif /* HAVE_GDBM || HAVE_BDB */
#endif /* USE_HCACHE */
WHERE char *MarkMacroPrefix;
WHERE char *MhFlagged;
WHERE char *MhReplied;
WHERE char *MhUnseen;
WHERE char *MsgFmt;

#ifdef USE_SOCKET
WHERE char *Preconnect INITVAL(NULL);
WHERE char *Tunnel INITVAL(NULL);
WHERE short NetInc;
#endif /* USE_SOCKET */

#ifdef MIXMASTER
WHERE char *Mixmaster;
WHERE char *MixEntryFormat;
#endif

WHERE struct List *Muttrc INITVAL(0);
#ifdef USE_NNTP
WHERE char *GroupFormat;
WHERE char *Inews;
WHERE char *NewsCacheDir;
WHERE char *NewsServer;
WHERE char *NewsgroupsCharset;
WHERE char *NewsRc;
WHERE char *NntpAuthenticators;
WHERE char *NntpUser;
WHERE char *NntpPass;
#endif
WHERE char *Outbox;
WHERE char *Pager;
WHERE char *PagerFmt;
WHERE char *PipeSep;
#ifdef USE_POP
WHERE char *PopAuthenticators INITVAL(NULL);
WHERE short PopCheckTimeout;
WHERE char *PopHost;
WHERE char *PopPass INITVAL(NULL);
WHERE char *PopUser INITVAL(NULL);
#endif
WHERE char *PostIndentString;
WHERE char *Postponed;
WHERE char *PostponeEncryptAs;
WHERE char *Prefix;
WHERE char *PrintCmd;
WHERE char *NewMailCmd;
WHERE char *QueryCmd;
WHERE char *QueryFormat;
WHERE char *Realname;
WHERE short SearchContext;
WHERE char *SendCharset;
WHERE char *Sendmail;
WHERE char *Shell;
WHERE char *ShowMultipartAlternative;
#ifdef USE_SIDEBAR
WHERE char *SidebarDelimChars;
WHERE char *SidebarDividerChar;
WHERE char *SidebarFormat;
WHERE char *SidebarIndentString;
#endif
WHERE char *Signature;
WHERE char *SimpleSearch;
#ifdef USE_SMTP
WHERE char *SmtpAuthenticators INITVAL(NULL);
WHERE char *SmtpPass INITVAL(NULL);
WHERE char *SmtpUrl INITVAL(NULL);
#endif /* USE_SMTP */
WHERE char *Spoolfile;
WHERE char *SpamSep;
#ifdef USE_SSL
WHERE char *SslCertFile INITVAL(NULL);
WHERE char *SslClientCert INITVAL(NULL);
WHERE char *SslEntropyFile INITVAL(NULL);
WHERE char *SslCiphers INITVAL(NULL);
#ifdef USE_SSL_GNUTLS
WHERE short SslDHPrimeBits;
WHERE char *SslCACertFile INITVAL(NULL);
#endif
#endif
WHERE struct MbCharTable *StChars;
WHERE char *Status;
WHERE char *Tempdir;
WHERE struct MbCharTable *Tochars;
WHERE struct MbCharTable *Flagchars;
WHERE char *TrashPath;
WHERE char *TSStatusFormat;
WHERE char *TSIconFormat;
WHERE short TSSupported;
WHERE char *Username;
WHERE char *Visual;
WHERE char *XlabelDelim;

WHERE char *CurrentFolder;
WHERE char *LastFolder;


WHERE const char *GitVer;

WHERE struct Hash *Groups;
WHERE struct Hash *ReverseAlias;
#ifdef USE_NOTMUCH
WHERE struct Hash *TagTransforms;
WHERE struct Hash *TagFormats;
#endif

WHERE struct List *AutoViewList INITVAL(0);
WHERE struct List *AlternativeOrderList INITVAL(0);
WHERE struct List *AttachAllow INITVAL(0);
WHERE struct List *AttachExclude INITVAL(0);
WHERE struct List *InlineAllow INITVAL(0);
WHERE struct List *InlineExclude INITVAL(0);
WHERE struct List *HeaderOrderList INITVAL(0);
WHERE struct List *Ignore INITVAL(0);
WHERE struct List *MailtoAllow INITVAL(0);
WHERE struct List *MimeLookupList INITVAL(0);
WHERE struct List *UnIgnore INITVAL(0);

WHERE struct RxList *Alternates INITVAL(0);
WHERE struct RxList *UnAlternates INITVAL(0);
WHERE struct RxList *MailLists INITVAL(0);
WHERE struct RxList *UnMailLists INITVAL(0);
WHERE struct RxList *SubscribedLists INITVAL(0);
WHERE struct RxList *UnSubscribedLists INITVAL(0);
WHERE struct ReplaceList *SpamList INITVAL(0);
WHERE struct RxList *NoSpamList INITVAL(0);
WHERE struct ReplaceList *SubjectRxList INITVAL(0);


/* bit vector for the yes/no/ask variable type */
#ifdef MAIN_C
unsigned char QuadOptions[(OPT_MAX * 2 + 7) / 8];
#else
extern unsigned char QuadOptions[];
#endif

WHERE unsigned short Counter INITVAL(0);

#ifdef USE_NNTP
WHERE short NewsPollTimeout;
WHERE short NntpContext;
#endif

#ifdef DEBUG
WHERE short DebugLevel;
WHERE char *DebugDir;
WHERE char *DebugFile;
#endif

WHERE short ConnectTimeout;
WHERE short HistSize;
WHERE short MenuContext;
WHERE short PagerContext;
WHERE short PagerIndexLines;
WHERE short ReadInc;
WHERE short ReflowWrap;
WHERE short SaveHist;
WHERE short SendmailWait;
WHERE short SleepTime INITVAL(1);
WHERE short SkipQuotedOffset;
WHERE short TimeInc;
WHERE short Timeout;
WHERE short Wrap;
WHERE short WrapHeaders;
WHERE short WriteInc;

WHERE short ScoreThresholdDelete;
WHERE short ScoreThresholdRead;
WHERE short ScoreThresholdFlag;

#ifdef USE_SIDEBAR
WHERE short SidebarWidth INITVAL(0);
WHERE struct List *SidebarWhitelist INITVAL(0);
#endif

#ifdef USE_IMAP
WHERE short ImapKeepalive;
WHERE short ImapPipelineDepth;
#endif

/* flags for received signals */
WHERE SIG_ATOMIC_VOLATILE_T SigAlrm INITVAL(0);
WHERE SIG_ATOMIC_VOLATILE_T SigInt INITVAL(0);
WHERE SIG_ATOMIC_VOLATILE_T SigWinch INITVAL(0);

WHERE int CurrentMenu;

WHERE struct Alias *Aliases INITVAL(0);
WHERE struct List *UserHeader INITVAL(0);

/* -- formerly in pgp.h -- */
WHERE struct Regex PgpGoodSign;
WHERE struct Regex PgpDecryptionOkay;
WHERE char *PgpSignAs;
WHERE short PgpTimeout;
WHERE char *PgpEntryFormat;
WHERE char *PgpClearSignCommand;
WHERE char *PgpDecodeCommand;
WHERE char *PgpVerifyCommand;
WHERE char *PgpDecryptCommand;
WHERE char *PgpSignCommand;
WHERE char *PgpEncryptSignCommand;
WHERE char *PgpEncryptOnlyCommand;
WHERE char *PgpImportCommand;
WHERE char *PgpExportCommand;
WHERE char *PgpVerifyKeyCommand;
WHERE char *PgpListSecringCommand;
WHERE char *PgpListPubringCommand;
WHERE char *PgpGetkeysCommand;
WHERE char *PgpSelfEncryptAs;

/* -- formerly in smime.h -- */
WHERE char *SmimeDefaultKey;
WHERE short SmimeTimeout;
WHERE char *SmimeCertificates;
WHERE char *SmimeKeys;
WHERE char *SmimeCryptAlg;
WHERE char *SmimeCALocation;
WHERE char *SmimeVerifyCommand;
WHERE char *SmimeVerifyOpaqueCommand;
WHERE char *SmimeDecryptCommand;
WHERE char *SmimeSignCommand;
WHERE char *SmimeDigestAlg;
WHERE char *SmimeEncryptCommand;
WHERE char *SmimeGetSignerCertCommand;
WHERE char *SmimePk7outCommand;
WHERE char *SmimeGetCertCommand;
WHERE char *SmimeImportCertCommand;
WHERE char *SmimeGetCertEmailCommand;
WHERE char *SmimeSelfEncryptAs;

#ifdef USE_NOTMUCH
WHERE int NotmuchOpenTimeout;
WHERE char *NotmuchDefaultUri;
WHERE char *NotmuchExcludeTags;
WHERE char *NotmuchUnreadTag;
WHERE char *NotmuchHiddenTags;
WHERE char *VirtFolderFormat;
WHERE int NotmuchDBLimit;
WHERE char *NotmuchQueryType;
WHERE char *NotmuchRecordTags;
WHERE int NotmuchQueryWindowDuration;
WHERE char *NotmuchQueryWindowTimebase;
WHERE int NotmuchQueryWindowCurrentPosition;
WHERE char *NotmuchQueryWindowCurrentSearch;
#endif

#ifdef MAIN_C
const char *const Weekdays[] = {
    "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat",
};
const char *const Months[] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
    "Aug", "Sep", "Oct", "Nov", "Dec", "ERR",
};

const char *const BodyTypes[] = {
    "x-unknown", "audio",     "application", "image", "message",
    "model",     "multipart", "text",        "video",
};
const char *const BodyEncodings[] = {
    "x-unknown", "7bit",   "8bit",        "quoted-printable",
    "base64",    "binary", "x-uuencoded",
};
#else
extern const char *const Weekdays[];
extern const char *const Months[];
#endif

#endif /* _MUTT_GLOBALS_H */
