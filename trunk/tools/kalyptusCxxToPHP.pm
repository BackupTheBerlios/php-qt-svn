#***************************************************************************
#    copyright            : (C) 2005 Thomas Moenicke
#    email                : tm@ippfp.org
#    author               : Thomas Moenicke, based on the CSharp generation code
#                            by Adam Treat & Richard Dale.
#***************************************************************************/

#/***************************************************************************
# *                                                                         *
# *   This program is free software; you can redistribute it and/or modify  *
# *   it under the terms of the GNU General Public License as published by  *
# *   the Free Software Foundation; either version 2 of the License, or     *
# *   (at your option) any later version.                                   *
# *                                                                         *
#***************************************************************************/

# TODO: fit cplusplusToZEND, cplusplusToInvoke, cplusplusToMacro
# TODO: inheritance

package kalyptusCxxToPHP;

use File::Path;
use File::Basename;

use Carp;
use Ast;
use kdocAstUtil;
use kdocUtil;
use Iter;
use kalyptusDataDict;

use strict;
no strict "subs";

use vars qw/ @clist $host $who $now $gentext %functionId $docTop
	$lib $rootnode $outputdir $opt $debug $typeprefix $eventHandlerCount
	$pastaccess $pastname $pastreturn $pastparams $nullctor $constructorCount $paramCount @properties @functions *CLASS *ZEND_PHP_QT *HEADER *QTCTYPES *KDETYPES /;

BEGIN
{
	@clist = ();

	# Page footer

	$who = kdocUtil::userName();
	$host = kdocUtil::hostName();
	$now = localtime;
	$gentext = "$who using kalyptus $main::Version.";

	$docTop =<<EOF
 * begin           : $now
 * generated by    : $gentext
 */
EOF
}

# TODO here:
# one is needed for php types, one for zend types (e.q. zval)
sub cplusplusToZEND
{
	my ( $cplusplusType )  = @_;
	if ( $cplusplusType =~ /bool/ && kalyptusDataDict::ctypemap($cplusplusType) eq "int" ) {
		return "bool";
	} elsif ( kalyptusDataDict::ctypemap($cplusplusType) =~ /\s*void\s*\**/ ) {
		return "NULL";
	} elsif ( kalyptusDataDict::ctypemap($cplusplusType) =~ /\s*int\s*\&*/ ) {
		return "long";
	} elsif ( kalyptusDataDict::ctypemap($cplusplusType) =~ /\s*int\s*\*/) {
		return "int[]";
	} elsif ( kalyptusDataDict::ctypemap($cplusplusType) =~ /\s*double\s*\*/ ) {
		return "double[]";
	} elsif ( kalyptusDataDict::ctypemap($cplusplusType) =~ /\s*short\s*\*/ ) {
		return "short[]";
	} elsif ( $cplusplusType =~ /QByteArray/ || $cplusplusType =~ /QBitArray/ ) {
		return "byte[]";
	} elsif ( kalyptusDataDict::ctypemap($cplusplusType) =~ /\s*char\s*\*\*/ ) {
		return "char";
	} elsif ( kalyptusDataDict::ctypemap($cplusplusType) =~ /\s*char\s*\**/ ) {
		return "char* ";
	} elsif ( kalyptusDataDict::ctypemap($cplusplusType) =~ /\s*unsigned int\s*\**/ ) {
		return "uint";
	} elsif ( kalyptusDataDict::ctypemap($cplusplusType) =~ /\s*unsigned short\s*\**/ ) {
		return "ushort";
	} elsif ( kalyptusDataDict::ctypemap($cplusplusType) =~ /\s*unsigned long\s*\**/ ) {
		return "ulong";
	} elsif ( kalyptusDataDict::ctypemap($cplusplusType) =~ /\s*unsigned char\s*\**/ ) {
		return "string";
	} elsif ( $cplusplusType =~ /^GUID/ ) {
		return "System.Guid";
	} elsif ( $cplusplusType =~ /^FILE/ ) {
		return "string";
	} elsif ( $cplusplusType =~ /^_NPStream/ ) {
		return "IntPtr";
	} elsif ( $cplusplusType =~ /^QPtrCollection/ ) {
		return "IntPtr";
	} elsif ( $cplusplusType =~ /^QStyleHintReturn/ ) {
		return "IntPtr";
	} elsif ( $cplusplusType =~ /^type/i ) {
		return "IntPtr";
	} elsif ( $cplusplusType =~ /^Key/ || $cplusplusType =~ /^key_type/ || $cplusplusType =~ /^K/) {
		return "IntPtr";
	} elsif ( $cplusplusType =~ /^QUnknownInterface/ ) {
		return "IntPtr";
	} elsif ( $cplusplusType =~ /^GDHandle/ ) {
		return "IntPtr";
	} elsif ( $cplusplusType =~ /^QTextParag/ ) {
		return "IntPtr";
	} elsif ( $cplusplusType =~ /^QDiskFont/ ) {
		return "IntPtr";
	} elsif ( $cplusplusType =~ /^QDomNodePrivate/ ) {
		return "IntPtr";
	} elsif ( $cplusplusType =~ /^Display/ ) {
		return "IntPtr";
	} elsif ( $cplusplusType =~ /^QUuid/ ) {
		return "IntPtr";
	} elsif ( $cplusplusType =~ /^Q_REFCOUNT/ ) {
		return "IntPtr";
	} elsif ( $cplusplusType =~ /^EventRef/ ) {
		return "IntPtr";
	} elsif ( $cplusplusType =~ /^MSG/ ) {
		return "IntPtr";
	} elsif ( $cplusplusType =~ /^QWSEvent/ ) {
		return "IntPtr";
	} elsif ( $cplusplusType =~ /^XEvent/ ) {
		return "IntPtr";
	} elsif ( $cplusplusType =~ /^CGContextRef/ ) {
		return "IntPtr";
	} elsif ( $cplusplusType =~ /^QWSDecoration/ ) {
		return "IntPtr";
	} elsif ( $cplusplusType =~ /^QTextFormat/ || $cplusplusType =~ /^QTextDocument/ || $cplusplusType =~ /^QTextCursor/ ) {
		return "IntPtr";
	} elsif ( $cplusplusType =~ /^QSqlRecordPrivate/ ) {
		return "IntPtr";
	} elsif ( $cplusplusType =~ /^Text/ ) {
		return "IntPtr";
	} elsif ( $cplusplusType =~ /^Event/ ) {
		return "IntPtr";
	} elsif ( $cplusplusType =~ /^NavDirection/ ) {
		return "IntPtr";
	} elsif (
			$cplusplusType =~ /^pointer$/
			 || $cplusplusType =~/T\*$/
			 || $cplusplusType =~/T\&*$/
			 || $cplusplusType =~/T1\&*$/
			 || $cplusplusType =~/T2\&*$/
			 || $cplusplusType =~/^Iterator/i
			 || $cplusplusType =~/^_iterator/i
			 || $cplusplusType =~/^reference/
			 || $cplusplusType =~/^_reference/) {
		return "IntPtr";
	} elsif ($cplusplusType =~ /::/ || kalyptusDataDict::ctypemap($cplusplusType) =~ /::/ ||
			 $cplusplusType =~ /&$/ || kalyptusDataDict::ctypemap($cplusplusType) =~ /&$/ ||
			 $cplusplusType =~ /\*/ || kalyptusDataDict::ctypemap($cplusplusType) =~ /\*/) {

#		$cplusplusType =~ s/::/./g;
#		$cplusplusType =~ s/&//g;
#		$cplusplusType =~ s/\*//g;
#		return $cplusplusType;
        return "zval*";

	} else {
 		return kalyptusDataDict::ctypemap($cplusplusType);
	}
}

sub cplusplusToPInvoke
{
	my ( $cplusplusType )  = @_;
	if ( $cplusplusType =~ /bool/ && kalyptusDataDict::ctypemap($cplusplusType) eq "int" ) {
		return "bool";
	} elsif ( kalyptusDataDict::ctypemap($cplusplusType) =~ /\s*void\s*\*/ ) {
		return "int";
	} elsif ( kalyptusDataDict::ctypemap($cplusplusType) =~ /\s*int\s*\&*/ ) {
		return "int";
	} elsif ( kalyptusDataDict::ctypemap($cplusplusType) =~ /\s*int\s*\*/) {
		return "int[]";
	} elsif ( kalyptusDataDict::ctypemap($cplusplusType) =~ /\s*double\s*\*/ ) {
		return "double[]";
	} elsif ( kalyptusDataDict::ctypemap($cplusplusType) =~ /\s*short\s*\*/ ) {
		return "short[]";
	} elsif ( $cplusplusType =~ /QByteArray/ || $cplusplusType =~ /QBitArray/ ) {
		return "byte[]";
	} elsif ( kalyptusDataDict::ctypemap($cplusplusType) =~ /\s*char\s*\*\*/ ) {
		return "string[]";
	} elsif ( kalyptusDataDict::ctypemap($cplusplusType) =~ /\s*char\s*\**/ ) {
		return "string";
	} elsif ( kalyptusDataDict::ctypemap($cplusplusType) =~ /\s*unsigned int\s*\**/ ) {
		return "uint";
	} elsif ( kalyptusDataDict::ctypemap($cplusplusType) =~ /\s*unsigned short\s*\**&*/ ) {
		return "ushort";
	} elsif ( kalyptusDataDict::ctypemap($cplusplusType) =~ /\s*unsigned long\s*\**/ ) {
		return "ulong";
	} elsif ( kalyptusDataDict::ctypemap($cplusplusType) =~ /\s*unsigned char\s*\**/ ) {
		return "string";
	} elsif ( $cplusplusType =~ /^GUID/ ) {
		return "System.Guid";
	} elsif ( $cplusplusType =~ /^FILE/ ) {
		return "string";
	} elsif ( $cplusplusType =~ /^_NPStream/ ) {
		return "RawObject";
	} elsif ( $cplusplusType =~ /^QPtrCollection/ ) {
		return "RawObject";
	} elsif ( $cplusplusType =~ /^QStyleHintReturn/ ) {
		return "RawObject";
	} elsif ( $cplusplusType =~ /^type/i ) {
		return "RawObject";
	} elsif ( $cplusplusType =~ /^Key/ || $cplusplusType =~ /^key_type/ || $cplusplusType =~ /^K/) {
		return "RawObject";
	} elsif ( $cplusplusType =~ /^QUnknownInterface/ ) {
		return "RawObject";
	} elsif ( $cplusplusType =~ /^GDHandle/ ) {
		return "RawObject";
	} elsif ( $cplusplusType =~ /^QTextParag/ ) {
		return "RawObject";
	} elsif ( $cplusplusType =~ /^QDiskFont/ ) {
		return "RawObject";
	} elsif ( $cplusplusType =~ /^QDomNodePrivate/ ) {
		return "RawObject";
	} elsif ( $cplusplusType =~ /^Display/ ) {
		return "RawObject";
	} elsif ( $cplusplusType =~ /^QUuid/ ) {
		return "RawObject";
	} elsif ( $cplusplusType =~ /^Q_REFCOUNT/ ) {
		return "RawObject";
	} elsif ( $cplusplusType =~ /^EventRef/ ) {
		return "RawObject";
	} elsif ( $cplusplusType =~ /^MSG/ ) {
		return "RawObject";
	} elsif ( $cplusplusType =~ /^QWSEvent/ ) {
		return "RawObject";
	} elsif ( $cplusplusType =~ /^XEvent/ ) {
		return "RawObject";
	} elsif ( $cplusplusType =~ /^CGContextRef/ ) {
		return "RawObject";
	} elsif ( $cplusplusType =~ /^QWSDecoration/ ) {
		return "RawObject";
	} elsif ( $cplusplusType =~ /^QTextFormat/ || $cplusplusType =~ /^QTextDocument/ || $cplusplusType =~ /^QTextCursor/ ) {
		return "RawObject";
	} elsif ( $cplusplusType =~ /^QSqlRecordPrivate/ ) {
		return "RawObject";
	} elsif ( $cplusplusType =~ /^Text/ ) {
		return "RawObject";
	} elsif ( $cplusplusType =~ /^Event/ ) {
		return "RawObject";
	} elsif ( $cplusplusType =~ /^NavDirection/ ) {
		return "RawObject";
	} elsif (
			$cplusplusType =~ /^pointer$/
			 || $cplusplusType =~/T\*$/
			 || $cplusplusType =~/T\&*$/
			 || $cplusplusType =~/T1\&*$/
			 || $cplusplusType =~/T2\&*$/
			 || $cplusplusType =~/^iterator/i
			 || $cplusplusType =~/^_iterator/i
			 || $cplusplusType =~/^reference/
			 || $cplusplusType =~/^_reference/) {
		return "RawObject";
	} elsif ( $cplusplusType =~ /&$/ || kalyptusDataDict::ctypemap($cplusplusType) =~ /&$/ ) {
		return "IntPtr";
	} elsif ( $cplusplusType =~ /\*/ || kalyptusDataDict::ctypemap($cplusplusType) =~ /\*/ ) {
		return "IntPtr";
	} else {
		return kalyptusDataDict::ctypemap($cplusplusType);
	}
}

sub cplusplusToMacro
{
	my ( $class, $cnode )  = @_;
    
    my $functionname = $cnode->{astNodeName};
    my $classname = $class->{astNodeName};

    my $function = $cnode;  # for better reading
    my $access = $function->{Access};
    my $returntype = $function->{ReturnType};

# skip
    if ($functionname eq "qObject") {
        print CLASS "// skip ",$functionname,"\n";
        return;
    }

# make sure that this function will be added only at one time
    my $mark = 0;
    my $func;
    foreach $func ( @functions ) {
        if ( $func eq $functionname ) {
            print CLASS "// marked for overloading: ",$functionname,"\n";
            return;
        }
    }
    if (!$mark) {
        push @functions, $functionname;
    }

    print CLASS "
/*********************************
 *    class     ",$classname,"
 *    function  ",$functionname,"
 *    flags:    ",$function->{Flags},"
 *\n";
 
    my $count = 0;
    foreach $b ( @{$cnode->{ParamList}} ) {
        print CLASS " *    \@param   ",$b->{ArgType},"\n";
    } 
    if (!$count) {
        print CLASS " *    \@param   -\n";
    }
 
    print CLASS "
 *    \@access   ",$access,"
 *    \@return   ",$returntype,"
*********************************/
";

    # skip virtuals
    if ( $function->{Flags} =~ /v/ ){
        print CLASS "ZEND_METHOD(",$classname,", ",$functionname,"){\n";
        print CLASS "// marked as virtual, skipped\n";
        print CLASS "\tphp_printf(\"%s(): virtual functions are not yet implemented",'\n',"\",get_active_function_name(TSRMLS_C));\n";
        print CLASS "}\n";
        return;
    }

    print CLASS "ZEND_METHOD(",$classname,", ",$functionname,"){\n";

    my $count = 0;
    my $paratype; # for zend
    my $short = ",\"";
    my $paraf;  # for qt
    my @objects;

# write method implementation
    foreach $b ( @{$cnode->{ParamList}} ) {

        if($count > 0){
            $paraf .= ", ";
        }
# todo: bool, double
        if ( $b->{ArgType} =~ /char/ ) {
            print CLASS "\tchar* var_",$count,";\n";
            print CLASS "\tint* len_",$count,";\n\n";
            $paratype .= ", &var_".$count.", &len_".$count;
            $paraf .= " var_".$count;
            $short .= "s";
        } elsif ( $b->{ArgType} =~ /int/ ) {
            print CLASS "\tlong var_",$count,";\n";
            $paratype .= ", &var_".$count;
            $paraf .= " (".$b->{ArgType}.") var_".$count;
            $short .= "l";
        } 
        else {
            print CLASS "\tzval* var_",$count,";\n\n";
            $paratype .= ", &var_".$count;
            $paraf .= " var_".$count;
            $short .= "o";
            push @objects, "var_".$count;
        }

        $count++;
    }
    $short .= "\"";

    if( $count ) {
        print CLASS "\tif(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC",$short,$paratype,") == FAILURE) {\n";
        print CLASS "\t\tRETURN_FALSE;\n";
        print CLASS "\t}\n";
    }

# properties:
    # we have a nxn relation
    my $prop;
    my $obj_tmp;
    
    foreach $prop ( @properties ) {
     
       if ( $prop->{WRITE} =~ /$functionname/ ) {
        foreach $obj_tmp ( @properties ) {
            # mostly these methods are setmethods with only one argument
            # maybe source of error
# todo: test with QLCDNumber            
            my $postfix = cplusplusToZEND($prop->{type});
            $postfix =~ s/zval\*//;
            if ( $postfix ) {    
                $postfix = "_".cplusplusToZEND($prop->{type});
            }

            print CLASS  "\tzend_update_property",$postfix,"(Z_OBJCE_P(getThis()),getThis(),\"",$prop->{astNodeName},"\",strlen(\"",$prop->{astNodeName},"\"),var_0 TSRMLS_CC);\n";
            print CLASS "}\n";
            return;
        }
       }
    }

    my $rt = cplusplusToZEND($returntype);

    my $obj;

        foreach $obj ( @objects ) {
            print CLASS "\tQObject* tmp_",$obj," = (QObject*) php_qt_fetch(",$obj,");\n";
            $paraf =~ s/$obj/tmp_$obj/;
        }

        print CLASS "\t$classname *o = ($classname*) PHP_QT_FETCH();\n";


        if ( $rt eq "NULL" ) {
            print CLASS "\to->",$functionname,"(",$paraf,");\n";
            print CLASS "\tRETURN_NULL();\n";
        } elsif ( $rt =~ /zval/ ) {

# TODO: consider 'const',
# and non-pointer types, pointer types
            print CLASS "\t",$returntype," obj = (",$returntype,") o->",$functionname,"(",$paraf,");\n";
            print CLASS "\tzend_class_entry *ce;                                   \n";
#            print CLASS "\tif(obj != NULL) {                                       \n";
            print CLASS "\t    object_init_ex(return_value, ",$classname,"_ce_ptr);     \n";
            print CLASS "\t    zend_rsrc_list_entry le;                            \n";
            print CLASS "\t    le.ptr = &obj;                                       \n";
            print CLASS "\t    php_qt_register(return_value,le);                   \n";
            print CLASS "\t    return;                                             \n";
#            print CLASS "\t}                                                       \n";
#            print CLASS "\telse                                                    \n";
#            print CLASS "\t    RETURN_NULL();                                      \n";


        } else {
            print CLASS "\tRETURN_",uc($rt),"(o->",$functionname,"(",$paraf,"));\n" if defined $rt;
        }

    print CLASS "}\n";

    if( $cnode->{Flags} =~ /s/ ){
        $access .= "|ZEND_ACC_STATIC";
    }
# __construct
    print ZEND_PHP_QT "\nZEND_METHOD(",$class->{astNodeName},", ",$functionname,");";
# code snippets for php_qt.cpp here
    $access = uc($access);
    $access =~ s/_SLOTS//;
    $access =~ s/_SIGNALS//;
    print PHP_QT_CPP "\tZEND_ME(",$classname,",",$functionname,",NULL,ZEND_ACC_",$access,")\n";

}

sub writeDoc
{
	( $lib, $rootnode, $outputdir, $opt ) = @_;

	$debug = $main::debuggen;

	mkpath( $outputdir ) unless -f $outputdir;

    # make zend_php_qt.h header file
	my $file_zend_php_qt = "$outputdir/zend_php_qt.h";
	open( ZEND_PHP_QT, ">$file_zend_php_qt" ) || die "Couldn't create $file_zend_php_qt\n";
	$file_zend_php_qt =~ s/\.h/.h/;

    print ZEND_PHP_QT "/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2004 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.0 of the PHP license,       |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_0.txt.                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license\@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/
/*
 * Copyright (C) 2005 
 * Thomas Moenicke <tm\@ippfp.org>, 
 * Jean-Luc Gyger <jean_luc.gyger\@freesurf.ch>
 *
*/
/* \$Id: header,v 1.15 2004/01/08 16:46:52 sniper Exp \$ */

#ifndef PHP_PHP_QT_H
#define PHP_PHP_QT_H

extern zend_module_entry php_qt_module_entry;
#define phpext_php_qt_ptr &php_qt_module_entry

#ifdef ZTS
#include \"TSRM.h\"
#endif

PHP_MINIT_FUNCTION(php_qt);
PHP_MSHUTDOWN_FUNCTION(php_qt);
PHP_RINIT_FUNCTION(php_qt);
PHP_RSHUTDOWN_FUNCTION(php_qt);
PHP_MINFO_FUNCTION(php_qt);

PHP_FUNCTION(confirm_php_qt_compiled);	/* For testing, remove later. */

/* emulate SIGNAL(), SLOT() macros */
PHP_FUNCTION(SIGNAL);
PHP_FUNCTION(SLOT);
    \n\n";

    # make zend_php.cpp snippets file
	my $file_php_qt_cpp = "$outputdir/php_qt.snippets.cpp";
	open( PHP_QT_CPP, ">$file_php_qt_cpp" ) || die "Couldn't create $file_php_qt_cpp\n";
	$file_php_qt_cpp =~ s/\.h/.h/;

    print PHP_QT_CPP "/**/\n";

    # make zend_php.cpp second snippets file PHP_MINIT_FUNCTION
	my $file_php_qt_minit = "$outputdir/php_qt.snippets2.cpp";
	open( PHP_QT_MINIT, ">$file_php_qt_minit" ) || die "Couldn't create $file_php_qt_minit\n";
	$file_php_qt_minit =~ s/\.h/.h/;

    print PHP_QT_CPP "\n";
    print PHP_QT_MINIT "\n";


	# Document all compound nodes
	Iter::LocalCompounds( $rootnode, sub { writeClassDoc( shift ); } );

    print ZEND_PHP_QT "\n/* 
  	Declare any global variables you may need between the BEGIN
	and END macros here:     

ZEND_BEGIN_MODULE_GLOBALS(php_qt)
	long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(php_qt)
*/

/* In every utility function you add that needs to use variables 
   in php_php_qt_globals, call TSRMLS_FETCH(); after declaring other 
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as PHP_QT_G(variable).  You are 
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define PHP_QT_G(v) TSRMG(php_qt_globals_id, zend_php_qt_globals *, v)
#else
#define PHP_QT_G(v) (php_qt_globals.v)
#endif

#endif	/* PHP_PHP_QT_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */\n
    ";
    close ZEND_PHP_QT;

    print PHP_QT_CPP "\n";
    close PHP_QT_CPP;

}

sub writeClassDoc
{
	my( $node ) = @_;

    $constructorCount = 0;
    $paramCount = 0;

	print "Enter: $node->{astNodeName}\n" if $debug;
	if( exists $node->{ExtSource} ) {
		warn "Trying to write doc for ".$node->{AstNodeName}.
			" from ".$node->{ExtSource}."\n";
		return;
	}

	my $typeName = $node->{astNodeName}."*";

	if ( kalyptusDataDict::ctypemap($typeName) eq "" ) {
		$typeprefix = ($typeName =~ /^Q/ ? "qt_" : "kde_");
		kalyptusDataDict::setctypemap($typeName, $typeprefix.$node->{astNodeName}."*");
		print "'$typeName' => '$typeprefix$typeName',\n";
	} elsif ( kalyptusDataDict::ctypemap($typeName) =~ /^qt_/ ) {
		$typeprefix = "qt_";
	} elsif ( kalyptusDataDict::ctypemap($typeName) =~ /^kde_/ ) {
		$typeprefix = "kde_";
	} else {
		$typeprefix = "kde_";
	}
# make the file
	my $file = "$outputdir/".join("__", kdocAstUtil::heritage($node)).".cpp";
	my $docnode = $node->{DocNode};
	my @list = ();
	my $version = undef;
	my $author = undef;

	if( $#{$node->{Kids}} < 0 || $node->{Access} eq "private") {
		return;
	}

	open( CLASS, ">$file" ) || die "Couldn't create $file\n";
	$file =~ s/\.h/.cpp/;

	my $short = "";
	my $extra = "";

print CLASS "/*
 * PHP-Qt - The PHP language bindings for Qt
 *
 * Copyright (C) 2005 
 * Thomas Moenicke <tm\@ippfp.org>, 
 * Jean-Luc Gyger <jean_luc.gyger\@freesurf.ch>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
";

	print CLASS " * ", $node->{astNodeName}, ".cpp - ", $node->{astNodeName}, " PHP implementation.\n";
	print CLASS $docTop;

    print CLASS "
#include <iostream>
using namespace std;

#include \"../php_qt.h\"\n";

# php_qt.cpp
    print PHP_QT_CPP "static zend_function_entry ",$node->{astNodeName},"_methods[] = {\n";
    print PHP_QT_MINIT "\n\t_register_",$node->{astNodeName},"(TSRMLS_C);\n";

	# ancestors
	my @ancestors = ();
	Iter::Ancestors( $node, $rootnode, undef, undef,
		sub { # print
			my ( $ances, $name, $type, $template ) = @_;
			push @ancestors, $name;
			},
			undef
		);

	if ( $#ancestors < 0 ) {
# INTERFACE
		if ( kalyptusDataDict::interfacemap($node->{astNodeName}) ne () ) {
			$file = "$outputdir/".join("__", kdocAstUtil::heritage($node)).".cpp";
			my $interfaceName = kalyptusDataDict::interfacemap($node->{astNodeName});
			$file =~ s/$node->{astNodeName}/$interfaceName/;
			open( INTERFACE, ">$file" ) || die "Couldn't create $file\n";
			print INTERFACE "// ", kalyptusDataDict::interfacemap($node->{astNodeName}), ".cpp - ", kalyptusDataDict::interfacemap($node->{astNodeName}), " PHP implementation.";
			print INTERFACE $docTop;	# header
print INTERFACE "
/*
 * PHP-Qt - The PHP language bindings for Qt
 *
 * Copyright (C) 2005 
 * Thomas Moenicke <tm\@ippfp.org>, 
 * Jean-Luc Gyger <jean_luc.gyger\@freesurf.ch>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <iostream>
using namespace std;

#include \"../php_qt.h\"
";
		}

# CLASS
	} else {

        print CLASS "\n#include <$node->{astNodeName}>\n\n";
        print ZEND_PHP_QT "\n\n/* $node->{astNodeName} */";

	}
# JNISOURCE? seems to be from JNI
	Iter::MembersByType ( $node,
		sub { print CLASS "", $_[0], ""; print JNISOURCE "", $_[0], "";  },
		sub {	my ($node, $kid ) = @_;
                 generateClassMethodForEnum( $node, $kid );
               },
		sub { print CLASS ""; print JNISOURCE ""; }
	);

	Iter::MembersByType ( $node,
		sub { print CLASS "", $_[0], ""; print CLASS "", $_[0], "";  },
		sub {	my ($node, $kid ) = @_;
            if ($kid->{NodeType} eq "property"){
                push @properties, $kid;
            }
        },
		sub { print CLASS ""; print CLASS ""; }
	);

# methods
	%functionId = ();
	$eventHandlerCount = 0;

	Iter::MembersByType ( $node,
		sub { print CLASS "", $_[0], ""; print CLASS "", $_[0], ""; },
		sub {	my ($node, $kid ) = @_;
                               listMember( $node, $kid );
                         },
		sub { print CLASS ""; print CLASS ""; }
	);

    print CLASS "\n";
	close CLASS;
	$nullctor = 0;

# php_qt.cpp
    print PHP_QT_CPP "
	{NULL,NULL,NULL}
};\n";

# inheritance
        my $zend_inherit = $node->{astNodeName}."_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);";
        my $ancestor;

		foreach $ancestor ( @ancestors ) {
            $zend_inherit = $node->{astNodeName}."_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, ".$ancestor."_ce_ptr,NULL TSRMLS_CC);\n";
            last; # skip, not multiple
		}

    print PHP_QT_CPP "
void _register_",$node->{astNodeName},"(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,\"",$node->{astNodeName},"\",",$node->{astNodeName},"_methods);
    ",$zend_inherit,"
";

	Iter::MembersByType ( $node,
		sub { print CLASS "", $_[0], ""; print CLASS "", $_[0], "";  },
		sub {	my ($node, $kid ) = @_;
            if ($kid->{NodeType} eq "property"){
                print PHP_QT_CPP
#                    "zend_declare_property_string(",$node->{astNodeName},"_ce_ptr,\"",$kid->{astNodeName},"\",strlen(\"",$kid->{astNodeName},"\"),\"\",ZEND_ACC_PROTECTED TSRMLS_CC);";
                     "\tPHP_QT_DECLARE_PROPERTY(\"$kid->{astNodeName}\");\n";
            }
        },
		sub { print CLASS ""; print JNISOURCE ""; }
	);

    print PHP_QT_CPP "
}\n";

	if ( kalyptusDataDict::interfacemap($node->{astNodeName}) ne () ) {
		close INTERFACE;
    }
    
    undef @properties;
    undef @functions;
}

# for every node
sub listMember
{
	my( $class, $m, $ancestorCount) = @_;
	my $name;
    my $function;
	my $PHPaccess;
	my $PHPparams;
    my $PHPzend_parse_parameters_s;
    my $PHPzend_parse_parameters_vars;
    my @PHPinformations;
	my $returnType;

	$name = $m->{astNodeName} ;
	my $type = $m->{NodeType};
	my $docnode = $m->{DocNode};

	if ( $m->{ReturnType} =~ /~/ ) {
		$name = "~".$name;
	}

#print_r($m);

    $function = $name;

	$function =~ s/~//;

	if( $type eq "method" && $m->{Access} ne "private" && $m->{Access} ne "private_slots" && $m->{Access} ne "signals" ) {
		if ( $m->{ReturnType} =~ /[<>]/ || $m->{Params} =~ /[<>]/  || $m->{Params} =~ /\.\.\./ || $m->{Params} =~ /Impl/
				|| $m->{ReturnType} =~ /QAuBucket/ || $m->{Params} =~ /QAuBucket/
				|| $m->{ReturnType} =~ /QMember/ || $m->{Params} =~ /QMember/   ) {
			return;
		}

# returntype
		$returnType = $m->{ReturnType};
		$returnType =~ s/const\s*//;
		$returnType =~ s/inline\s*//;
		$returnType =~ s/\s*([,\*\&])\s*/$1/;
		$returnType =~ s/^\s*//;
		$returnType =~ s/\s*$//;

		if ( $returnType ne "" && cplusplusToPInvoke($returnType) eq () ) {
			$returnType =~ s/^.*::.*$/int/;
		} else {
			$returnType = cplusplusToPInvoke($returnType);
		}

		if ( $returnType eq "RawObject") {
			$returnType = "IntPtr";
		}

		my $cparams = $m->{Params};
		my $cplusplusparams;
		my $pinvokeparams;
		my $pinvokeargs;

		# TODO port to $m->{ParamList}
		$cparams =~ s/\s+/ /g;
		$cparams =~ s/\s*([,\*\&])\s*/$1 /g;
		$cparams =~ s/^\s*void\s*$//;
		my $argId = 0;
		my @cargs = kdocUtil::splitUnnested(",", $cparams);
		$cparams = "";
		foreach my $arg ( @cargs ) {
			my $argType;
			my $cargType;
			my $PHPargType;
			my $pinvokeargType;
			if ( $arg =~ /^\s*$/ ) {
				next;
			}

			# A '<arg> = <value>' default parameter
			$arg =~ s/\s*([^\s].*[^\s])\s*/$1/;
			$arg =~ s/(\w+)\[\]/\* $1/;
			$arg =~ s/=\s*(("[^\"]*")|(\'.\')|(([-\w:.]*)\s*(\|\s*[-\w]*)*(\(\w*\))?))//;

			if ( $arg =~ /^(.*)\s+(\w+)\s*$/ ) {
				$argType = $1;
				$arg = $2;
			} else {
				$argType = $arg;
				$argId++;
				$arg = "arg".$argId;
			}
			$arg =~ s/^id$/identifier/;
			$argType =~ s/\s*([^\s].*[^\s])\s*/$1/;
			$argType =~ s/\s*const//g;
			$argType =~ s/^\s*//;
			$argType =~ s/([\*\&])\s*([\*\&])/$1$2/;
			$cargType = kalyptusDataDict::ctypemap($argType);
			$PHPargType = cplusplusToZEND($argType);
			$pinvokeargType = cplusplusToPInvoke($argType);

			if ( $PHPargType eq "" ) {
				$PHPargType = $argType;
				$PHPargType =~ s/\&/\*/;
				$PHPargType =~ s/^.*::.*$/int/;
			}
			if ( $pinvokeargType eq "" ) {
				$pinvokeargType = $argType;
				$pinvokeargType =~ s/\&/\*/;
				$pinvokeargType =~ s/^.*::.*$/int/;
			}

			if ( $pinvokeargType =~ /IntPtr/ ) {
				$pinvokeargs .= "$arg.Ptr, ";
 			} elsif ( $PHPargType =~ /\./ ) {
				$pinvokeargs .= "($pinvokeargType)$arg, ";
			} else {
				$pinvokeargs .= "$arg, ";
			}

			if ( $pinvokeargType =~ /RawObject/ ) {
				 $pinvokeargType =~ s/RawObject/IntPtr/;
			}

            @PHPinformations[$paramCount] = [$PHPargType,$arg];

            $PHPparams .= "$PHPargType $arg, ";
            $paramCount++;
            $pinvokeparams .= "$pinvokeargType $arg, ";
		}
		$cparams =~ s/, $//;
		$cplusplusparams =~ s/, $//;
		$PHPparams =~ s/, $//;
		$pinvokeparams =~ s/, $//;
		$pinvokeargs =~ s/, $//;

		my $flags = $m->{Flags};

		if ( !defined $flags ) {
			warn "Method ".$m->{astNodeName}.  " has no flags\n";
		}


		my $extra = "";
		$extra .= "static " if $flags =~ "s";

		if ( $name =~ /operator/  ) {
			return;
		}

		if ( $m->{Access} =~ /protected/ && $name ne $class->{astNodeName}  ) {
			if ( $class->{Pure} ) {
				return;
			}

			$name = "protected_".$name;
		}

		$m->{Access} =~ /([^_]*)(.*)?\s*/;
		$PHPaccess = $1;
		if ( $extra =~ /static/ ) {
			$PHPaccess .= " static";
		}

		if ( $name eq $class->{astNodeName} && $class->{Pure} ) {
			return;
		}

		if ( defined $docnode ) {
			if ( defined $docnode->{Text} ) {
				print CLASS "\n/** ";
				my $node;
				my $line;
				foreach $node ( @{$docnode->{Text}} ) {
					next if $node->{NodeType} ne "DocText";
					$line = $node->{astNodeName};
					print CLASS $line, "\n";
				}
				print CLASS "*/\n";
			}
		}

		#This is to make sure we have no duplicate methods...
		my $currentmethod .= "$name $returnType $PHPparams";
		my $pastmethod .= "$pastname $pastreturn $pastparams";
		if($currentmethod ne $pastmethod) {

# make the cpp file
		if ( $name eq $class->{astNodeName} ) {

# Constructor
            if($constructorCount == 0){

			    print CLASS "\n\nZEND_METHOD(",$function, ",__construct){\n";
    	        print CLASS "\t",$function, " *",$function,"_ptr = new ",$function,"();\n";
            }
# args
# here we should find a better solution for overloading
            if($paramCount > 0){
                print CLASS "\tif(ZEND_NUM_ARGS() == ",$paramCount,"){\n";
                print CLASS "\t\t/*",$pinvokeargs,"*/\n";            

                my $typeCount = 0;
		        foreach my $info ( @PHPinformations ) {
                    if(@{$info}[0] eq "long"){
                        $PHPzend_parse_parameters_s .= "l";
                        $PHPzend_parse_parameters_vars .= ", &var$typeCount";
                    } else {
                        $PHPzend_parse_parameters_s .= "o";
                        $PHPzend_parse_parameters_vars .= ", &var$typeCount";
                    }
                    print CLASS "\t\t",@{$info}[0]," var",$typeCount++,";\n";
                }

                print CLASS "\t\tif(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,\"",$PHPzend_parse_parameters_s,"\"",$PHPzend_parse_parameters_vars,") == FAILURE) {\n";
                print CLASS "\t\t\treturn;\n","\t\t}\n"; 
            
                my $typeCount = 0;
		        foreach my $info ( @PHPinformations ) {
                    my $Function_ = ucfirst(@{$info}[1]);            
                    print CLASS "\t\t//zend_update_property(Z_OBJCE_P(getThis()),getThis(),\"@{$info}[1]\",strlen(\"@{$info}[1]\"), var",$typeCount," TSRMLS_CC);\n";

                    if(@{$info}[0] eq "zval*"){
#                        print CLASS "\t\t",$function," *tmp = (",$function,"*) php_qt_fetch(var",$typeCount,");\n";
#                        print CLASS "\t\t",$function,"_ptr->set$Function_(tmp);\n";                
                    } elsif (@{$info}[0] eq "long"){
#                        print CLASS "\t\t",$function,"_ptr->set$Function_(var",$typeCount,");\n";
                    }
                    $typeCount++;
                }
                print CLASS "\t}\n";
            }

            $constructorCount++;

			if ($PHPparams eq () ) {
				$nullctor = 1;
			}
# Destructor
		} elsif ( $returnType =~ /~/  ) {
            print CLASS "\tPHP_QT_REGISTER(",$function,"_ptr);\n";
            print CLASS "\tRETURN_NULL();\n";
			print CLASS "}\n";        
            $constructorCount = 0;
            print CLASS "\nPHP_QT_DESTRUCT(",$function,");\n\n";

# methods
		} else {
			if ( $name =~ /.*Event$/ ) {
				return;
			}
            cplusplusToMacro($class,$m);
   		}
	}
	}
	#Part of the duplicate methods check.
	$pastname = $name;
	$pastreturn = $returnType;
	$pastparams = $PHPparams;

	$PHPparams = "";
    $PHPzend_parse_parameters_s = "";
    $PHPzend_parse_parameters_vars = "";

# paramCount counts params ;)
    $paramCount = 0;
}

sub generateClassMethodForEnum
{
	my( $class, $m ) = @_;
	my $enum = $m->{astNodeName};
	my $PHPaccess;

	$m->{Access} =~ /([^_]*)(.*)?\s*/;
	$PHPaccess = $1;

	if( $m->{NodeType} eq "enum" ) {
		my $enum = $m->{astNodeName};
		my @enums = split(",", $m->{Params});
		my $enumCount = 0;

		if($enum ne " ") {
			print CLASS "\n\n/*\t\t$PHPaccess enum", $enum,":long {";

			foreach my $enum_ ( @enums ) {
				$enum_ =~ s/\s//g;
				$enum_ =~ s/::/./g;
				if($#enums == $enumCount){

					if ( $enum_ =~ /(.*)=(.*)/ ) {
						print CLASS "\n\t\t\t$1 = $2";
					} else {
						print CLASS "\n\t\t\t$enum = $enumCount";
					}

				} else {

					if ( $enum_ =~ /(.*)=(.*)/ ) {
						print CLASS "\n\t\t\t$1 = $2,";
					} else {
						print CLASS "\n\t\t\t$enum = $enumCount,";
					}

				}
#                $enum =~ s/=//g;
                my @constant = split(/=/,$enum_);                
                print PHP_QT_MINIT "\t	REGISTER_LONG_CONSTANT(\"",uc($class->{astNodeName}),"_",uc($enum),"_",uc($constant[0]),"\", ",$class->{astNodeName},"::",$constant[0],", CONST_CS | CONST_PERSISTENT);\n";                
				$enumCount++;

			}

			print CLASS "\n\t\t}\n*/";
		}
	}
}

sub print_r
{
    my ( $cnode ) = @_;

    my @n = Ast::GetProps($cnode);
    foreach $a ( @n ) {
        print PHP_QT_CPP ">",$a,": ",$cnode->{$a},"\n";

    }



}

1;

