#***************************************************************************
#            kalyptusCxxToSmoke.pm -  Generates x_*.cpp files for smoke
#                             -------------------
#    begin                : Fri Jan 25 12:00:00 2000
#    copyright            : (C) 2002 Lost Highway Ltd. All Rights Reserved.
#    email                : david@mandrakesoft.com
#    author               : David Faure.
#***************************************************************************/

#/***************************************************************************
# *                                                                         *
# *   This program is free software; you can redistribute it and/or modify  *
# *   it under the terms of the GNU General Public License as published by  *
# *   the Free Software Foundation; either version 2 of the License, or     *
# *   (at your option) any later version.                                   *
# *                                                                         *
#***************************************************************************/

package kalyptusCxxToSmoke;

use File::Path;
use File::Basename;
use constant numSourceFiles => 20; # Total number of generated source files.
                                   # All classes will be distributed across those.

use Carp;
use Ast;
use kdocAstUtil;
use kdocUtil;
use Iter;
use kalyptusDataDict;

use strict;
no strict "subs";

use vars qw/
	$libname $rootnode $outputdir $opt $debug
	$methodNumber $headerSubdirectories
	%builtins %typeunion %allMethods %allTypes %enumValueToType %typedeflist %mungedTypeMap
	%skippedClasses /;

BEGIN
{

# Types supported by the StackItem union
# Key: C++ type  Value: Union field of that type
%typeunion = (
    'void*' => 's_voidp',
    'bool' => 's_bool',
    'char' => 's_char',
    'uchar' => 's_uchar',
    'short' => 's_short',
    'ushort' => 's_ushort',
    'int' => 's_int',
    'uint' => 's_uint',
    'long' => 's_long',
    'ulong' => 's_ulong',
    'float' => 's_float',
    'double' => 's_double',
    'enum' => 's_enum',
    'class' => 's_class'
);

# Mapping for iterproto, when making up the munged method names
%mungedTypeMap = (
     'QString' => '$',
     'QString*' => '$',
     'QString&' => '$',
     'QCString' => '$',
     'QCString*' => '$',
     'QCString&' => '$',
     'char*' => '$',
     'QCOORD*' => '?',
     'QRgb*' => '?',
     'Q_UINT64' => '$',
     'Q_INT64' => '$',
     'Q_LLONG' => '$',
     'quint64' => '$',
     'qint64' => '$',
     'long long' => '$',
     'qlonglong' => '$',
     'qulonglong' => '$',
     'WId' => '$',
     'Q_PID' => '$',
);

# Yes some of this is in kalyptusDataDict's ctypemap
# but that one would need to be separated (builtins vs normal classes)
%typedeflist =
(
   'signed char' => 'char',
   'unsigned char' => 'uchar',
   'signed short' => 'short',
   'unsigned short' => 'ushort',
   'signed' => 'int',
   'signed int' => 'int',
   'unsigned' => 'uint',
   'unsigned int' => 'uint',
   'signed long' => 'long',
   'unsigned long' => 'ulong',

# Anything that is not known is mapped to void*, so no need for those here anymore
#   'QWSEvent*'  =>  'void*',
#   'QDiskFont*'  =>  'void*',
#   'XEvent*'  =>  'void*',
#   'QStyleHintReturn*'  =>  'void*',
#   'FILE*'  =>  'void*',
#   'QUnknownInterface*'  =>  'void*',
#   'GDHandle'  =>  'void*',
#   '_NPStream*'  =>  'void*',
#   'QTextFormat*'  =>  'void*',
#   'QTextDocument*'  =>  'void*',
#   'QTextCursor*'  =>  'void*',
#   'QTextParag**'  =>  'void*',
#   'QTextParag*'  =>  'void*',
#   'QRemoteInterface*'  =>  'void*',
#   'QSqlRecordPrivate*'  =>  'void*',
#   'QTSMFI'  =>  'void*', # QTextStream's QTSManip
#   'const GUID&'  =>  'void*',
#   'QWidgetMapper*'  =>  'void*',
   'MSG*'  =>  'void*',
#   'const QSqlFieldInfoList&'  =>  'void*', # QSqlRecordInfo - TODO (templates)

   'QPtrCollection::Item'  =>  'void*', # to avoid a warning

   'void(* )()'  =>  'void*',
   'void (*)(void* )'  =>  'void*',
   'mode_t'  =>  'long',
   'QProcess::PID'  =>  'long',
   'size_type'  =>  'int', # QSqlRecordInfo
   'Qt::ComparisonFlags'  =>  'uint',
   'Qt::ToolBarDock'  =>  'int', # compat thing, Qt shouldn't use it
   'QIODevice::Offset'  =>  'ulong',
   'WState'  =>  'int',
   'QRgb'  =>  'uint',
   'ksocklen_t' => 'uint',
   'QCOORD'  =>  'int',
   'QTSMFI'  =>  'int',
   'Qt::WState'  =>  'int',
   'Qt::WFlags'  =>  'int',
   'Qt::HANDLE' => 'uint',
   'QEventLoop::ProcessEventsFlags' => 'uint',
   'QStyle::SCFlags' => 'int',
   'QStyle::SFlags' => 'int',
   'Q_INT16' => 'short',
   'qint16' => 'short',
   'Q_INT32' => 'int',
   'qint32' => 'int',
   'qint32&' => 'int&',
   'Q_INT8' => 'char',
   'qint8' => 'char',
   'Q_LONG' => 'long',
   'Q_UINT16' => 'ushort',
   'quint16' => 'ushort',
   'Q_UINT32' => 'uint',
   'quint32' => 'uint',
   'Q_UINT8' => 'uchar',
   'quint8' => 'uchar',
   'Q_ULONG' => 'long',
   'qreal' => 'double',
   'pid_t' => 'int',
   'size_t' => 'int',
   'pid_t' => 'int',
   'time_t' => 'int',
   'short int' => 'short',
   'signed long int' => 'long',
   'unsigned long int' => 'ulong',
   'unsigned short int' => 'ushort',
   'Qt::Alignment' => 'int',
   'Qt::Orientations' => 'int',
   'Qt::DockWidgetAreas' => 'int',
   'Qt::DropActions' => 'int',
   'Qt::ImageConversionFlags' => 'int',
   'Qt::ItemFlags' => 'int',
   'Qt::KeyboardModifiers' => 'int',
   'Qt::MatchFlags' => 'int',
   'Qt::MouseButtons' => 'int',
   'Qt::ToolBarAreas' => 'int',
   'Qt::WindowFlags' => 'int',
   'Qt::WindowStates' => 'int',
   'AutoFormatting' => 'int',
   'DirtyFlags' => 'int',
   'EditTriggers' => 'int',
   'FindFlags' => 'int',
   'Flags' => 'int',
   'FormattingOptions' => 'int',
   'GLenum' => 'int',
   'GLint' => 'int',
   'GLuint' => 'uint',
   'LoadOperator' => 'int',
   'NumberFlags' => 'int',
   'OpenMode' => 'int',
   'Options' => 'int',
   'PaintEngineFeatures' => 'int',
   'Permissions' => 'int',
   'PrintDialogOptions' => 'int',
   'ProcessEventsFlags' => 'int',
   'QDir::Filters' => 'int',
   'QDir::SortFlags' => 'int',
   'QFile::Permissions' => 'int',
   'QGL::FormatOptions' => 'int',
   'QIODevice::OpenMode' => 'int',
   'QImageReader::ImageReaderError' => 'int',
   'QItemSelectionModel::SelectionFlags' => 'int',
   'QPaintEngine::DirtyFlags' => 'int',
   'QPainter::RenderHints' => 'int',
   'QSql::ParamType' => 'int',
   'QTextDocument::FindFlags' => 'int',
   'Qt::DropActions' => 'int',
   'Qt::ImageConversionFlags' => 'int',
   'Qt::ItemFlags' => 'int',
   'Qt::KeyboardModifiers' => 'int',
   'Qt::MatchFlags' => 'int',
   'Qt::MouseButtons' => 'int',
   'Qt::ToolBarAreas' => 'int',
   'Qt::WindowFlags' => 'int',
   'Qt::WindowStates' => 'int',
   'RenderFlags' => 'int',
   'RenderHints' => 'int',
   'SortFlags' => 'int',
   'StepEnabled' => 'int',
   'Sections' => 'int',
   'Filters' => 'int',
   'SortFlags' => 'int',
   'QDir::Filters' => 'int',
   'QDir::SortFlags' => 'int',
   'QStyle::State' => 'int',
   'QValidator::State' => 'int',
   'QAbstractSpinBox::StepEnabled' => 'int',
   'QDockWidget::DockWidgetFeatures' => 'int',
   'QStyle::SubControls' => 'int',
   'RegisterOptions' => 'int',
   'BindMode' => 'int',
   'ButtonFeatures' => 'int',
   'CacheMode' => 'int',
   'CheckType' => 'int',
   'CornerWidgets' => 'int',
   'DockWidgetFeatures' => 'int',
   'FileFlags' => 'int',
   'FontFilters' => 'int',
   'FrameFeatures' => 'int',
   'GraphicsItemFlags' => 'int',
   'InterfaceFlags' => 'int',
   'IteratorFlags' => 'int',
   'MenuItemType' => 'int',
   'NumberOptions' => 'int',
   'PageBreakFlags' => 'int',
   'Qt::TextInteractionFlags' => 'int',
   'Relation' => 'int',
   'SectionPosition' => 'int',
   'SelectedPosition' => 'int',
   'StandardButtons' => 'int',
   'State' => 'int',
   'TabPosition' => 'int',
   'ToolBarFeatures' => 'int',
   'ToolBarPosition' => 'int',
   'ToolButtonFeatures' => 'int',
   'ViewItemFeatures' => 'int',
);

$headerSubdirectories = "kio/|phonon/ui/|kmediaplayer/|dnssd/|solid/|solid/ifaces/|phonon/|sonnet/|kdevelop/|kinterfacedesigner/|kontact/|kate/|kparts/|dom/|kabc/|ksettings/|kjs/|ktexteditor/|kdeprint/|kdesu/|knewstuff/|dbus-1.0/dbus/"

}

sub writeDoc
{
	( $libname, $rootnode, $outputdir, $opt ) = @_;

	print STDERR "Starting writeDoc for $libname...\n";

	$debug = $main::debuggen;

	mkpath( $outputdir ) unless -f $outputdir;

	# Define QPtrCollection::Item, for resolveType
	unless ( kdocAstUtil::findRef( $rootnode, "QPtrCollection::Item" ) || $main::qt4 ) {
		my $cNode = kdocAstUtil::findRef( $rootnode, "QPtrCollection" );
		warn "QPtrCollection not found" if (!$cNode);
		my $node = Ast::New( 'Item' );
		$node->AddProp( "NodeType", "Forward" );
		$node->AddProp( "Source", $cNode->{Source} ) if ($cNode);
		kdocAstUtil::attachChild( $cNode, $node ) if ($cNode);
		$node->AddProp( "Access", "public" );
	}
	
	print STDERR "Preparsing...\n";

	# Preparse everything, to prepare some additional data in the classes and methods
	Iter::LocalCompounds( $rootnode, sub { preParseClass( shift ); } );

	# Have a look at each class again, to propagate CanBeCopied
	Iter::LocalCompounds( $rootnode, sub { propagateCanBeCopied( shift ); } );

	print STDERR "Writing smokedata.cpp...\n";

	# Write out smokedata.cpp
	writeSmokeDataFile($rootnode);

	print STDERR "Writing x_*.cpp...\n";

	# Generate x_*cpp file for each class

        my $numclasses;
        Iter::LocalCompounds( $rootnode, sub { $numclasses++ } );
        my $classperfile = int($numclasses/numSourceFiles);
        print STDERR "Total number of classes: ". $numclasses ."\n" if $debug;
        my $nodelist = [];
        my $currentfile = 1;
        my $currentclass = 1;
        Iter::LocalCompounds( $rootnode, sub { 
                   push @$nodelist, shift;
                   if(@$nodelist == $classperfile and $currentfile != numSourceFiles)
                   {
                       print STDERR "Calling writeClassDoc for ". (scalar @$nodelist) . " classes\n" if $debug;
                       writeClassDoc( $nodelist );
                       $currentfile++;
                       $nodelist = []     
                   }
                   if(@$nodelist and $currentclass == $numclasses)
                   {    
                       print STDERR "Calling writeClassDoc for remaining ". (scalar @$nodelist) . " classes\n" if $debug;
                       writeClassDoc( $nodelist )
                   }
                   $currentclass++
        });

	print STDERR "Done.\n";
}

=head2 preParseClass
	Called for each class
=cut
sub preParseClass
{
	my( $classNode ) = @_;
	my $className = join( "::", kdocAstUtil::heritage($classNode) );

	if( $#{$classNode->{Kids}} < 0 ||
	    $classNode->{Access} eq "private" ||
	    $classNode->{Access} eq "protected" || # e.g. QPixmap::QPixmapData
	    exists $classNode->{Tmpl} ||
	    # Don't generate standard bindings for QString, this class is handled as a native type
	    $className eq 'QString' ||
	    $className eq 'QStringData' ||
	    $className eq 'QLatin1String' ||
	    $className eq 'QTLWExtra' ||
	    $className eq 'QWExtra' ||
	    $className eq 'QBig5Codec' ||
	    $className eq 'QBig5hkscsCodec' ||
	    $className eq 'QPtrCollection' ||
	    $className eq 'QGCache' ||
	    $className eq 'QConstString' ||
	    $className eq 'QCString' ||
	    # Don't map classes which are really arrays
	    $className eq 'QStringList' ||
            $className eq 'QCanvasItemList' ||
            $className eq 'QWidgetList' ||
            $className eq 'QObjectList' ||
	    $className eq 'QStrList' ||
	    $className eq 'KCmdLineOptions' ||
	    # Those are template related
            $className eq 'QTSManip' || # cause compiler errors with several gcc versions
	    $className eq 'QGDict' ||
	    $className eq 'QGList' ||
	    $className eq 'QGArray' ||
	    $className eq 'QGVector' ||
	    $className eq 'QStrIList' ||
	    $className eq 'QStrIVec' ||
	    $className eq 'QBitArray' ||
	    $className eq 'QMapData' ||
	    $className eq 'QMetaEnum::Item' ||
	    $className eq 'QWidgetContainerPlugin' ||
	    $className eq 'QGArray::array_data' ||
	    ($className eq 'QMenuItem' and $main::qt_embedded) ||
	    ($className eq 'QSignal' and $main::qt_embedded) ||
	    ($className eq 'QWSEvent' and $main::qt_embedded) ||
	    ($className eq 'QMetaObjectInit' and $main::qt_embedded) ||
	    ($className eq 'QKoi8Codec' and $main::qt_embedded) ||
	    $className eq 'KAccelGen' ||
	    ($className eq 'QAbstractUndoItem' and $main::qt4) ||
	    ($className eq 'QDebug' and $main::qt4) ||
	    ($className eq 'QNoDebug' and $main::qt4) ||
	    ($className eq 'QObjectData' and $main::qt4) ||
	    ($className eq 'QSysInfo' and $main::qt4) ||
	    ($className eq 'QPNGImageWriter' and $main::qt4) ||
	    ($className eq 'QPNGImagePacker' and $main::qt4) ||
	    ($className eq 'QSqlRelationalDelegate' and $main::qt4) ||
	    ($className eq 'QTextCodec::ConverterState' and $main::qt4) ||
	    ($className eq 'QTextLayout::Selection' and $main::qt4) ||
	    ($className eq 'QTextStreamManipulator' and $main::qt4) ||
	    $className eq 'DCOPArg' ||
	    $className eq 'DCOPReply' ||
	    $className eq 'KBookmarkMenu::DynMenuInfo' ||
	    $className eq 'KDateTime::Spec' ||
	    $className eq 'KEncodingFileDialog::Result' ||
	    $className eq 'KDE' ||
	    $className eq 'KDEDesktopMimeType::Service' ||
	    $className eq 'KDialogButtonBox' ||
	    $className eq 'KEntry' ||
	    $className eq 'KEntryKey' ||
	    $className eq 'KGlobalSettings::KMouseSettings' ||
	    $className eq 'KMimeType::Format' ||
	    $className eq 'KNotifyClient::Instance' ||
	    $className eq 'KParts::ComponentFactory' ||
	    $className eq 'KParts::Plugin::PluginInfo' ||
	    $className eq 'KParts::MainWindow' ||
	    $className eq 'KProtocolInfo::ExtraField' ||
	    $className eq 'KXMLGUIClient::StateChange' ||
	    $className eq 'KIconTheme' ||
	    $className eq 'KEditListBox::CustomEditor' ||
		$className eq 'KIO::KBookmarkMenuNSImporter' ||
		$className eq 'KIO::NetRC' ||
	    $className eq 'KExtendedSocket' ||
	    $className eq 'KSettings::PluginPage' ||
	    $className eq 'KSocket' ||
	    $className eq 'KPerDomainSettings' ||
	    $className eq 'KApplicationPropsPlugin' ||
	    $className eq 'KOpenWithHandler' ||
	    $className eq 'KFileOpenWithHandler' ||
	    $className eq 'KBindingPropsPlugin' ||
	    $className eq 'KPropsDlgPlugin' ||
	    $className eq 'KFileSharePropsPlugin' ||
	    $className eq 'KBookmarkMenuNSImporter' ||
	    $className eq 'KDevicePropsPlugin' ||
	    $className eq 'KDEDModule' ||
	    $className eq 'KFileMetaInfoProvider' ||
	    $className eq 'KFileMimeTypeInfo' ||
	    $className eq 'KMimeTypeChooserDialog' ||
	    $className eq 'KExecPropsPlugin' ||
	    $className eq 'KFilePermissionsPropsPlugin' ||
	    $className eq 'KImageFilePreview' ||
	    $className eq 'KBookmarkManager' ||
	    $className eq 'KBookmarkNotifier' ||
	    $className eq 'KOCRDialogFactory' ||
	    $className eq 'KExtendedBookmarkOwner' ||
	    $className eq 'KSharedPixmap' ||
	    $className eq 'KLibrary' ||
	    $className eq 'KScanDialogFactory' ||
	    $className eq 'KTimeZone::Transition' ||
	    $className eq 'KTipDatabase' ||
	    $className eq 'KBufferedIO' ||
	    $className eq 'KDictSpellingHighlighter' ||
		$className eq 'KPropertiesDialog' ||
	    $className eq 'ProgressItem' ||
	    $className eq 'KIO::ChmodInfo' ||
	    $className eq 'KUrl::List' ||
	    $className eq 'khtml::DrawContentsEvent' || # the khtml:: classes build, but don't link
	    $className eq 'khtml::MouseDoubleClickEvent' ||
	    $className eq 'khtml::MouseMoveEvent' ||
	    $className eq 'khtml::MousePressEvent' ||
	    $className eq 'khtml::MouseReleaseEvent' ||
	    $className eq 'khtml::MouseEvent' ||
	    $className eq 'khtml' ||
	    $className eq 'KURL::List' ||
	    $className eq 'KWin::Info' ||
	    $className eq 'TerminalInterface' ||
	    $className eq 'QAccessibleBridgePlugin' || # Qt4
	    $className eq 'QForeachContainerBase' || # Qt4
	    $className eq 'QInputMethodEvent::Attribute' || # Qt4
	    $className eq 'QAbstractUndoItem' || # Qt4
	    $className eq 'QAbstractTextDocumentLayout::PaintContext' || # Qt4
	    $className eq 'QAbstractTextDocumentLayout::Selection' || # Qt4
	    $className eq 'QBrushData' || # Qt4
	    $className eq 'QDBusObjectPath' || # Qt4
	    $className eq 'QDBusSignature' || # Qt4
	    $className eq 'QDBusVariant' || # Qt4
	    $className eq 'QIPv6Address' || # Qt4
	    $className eq 'QImageTextKeyLang' || # Qt4
	    $className eq 'QMap' || # Qt4
	    $className eq 'QMap::const_iterator' || # Qt4
	    $className eq 'QMap::iterator' || # Qt4
	    $className eq 'QMapData' || # Qt4
	    $className eq 'QMapData::Node' || # Qt4
	    $className eq 'QObjectData' || # Qt4
	    $className eq 'QProxyModel' || # Obsolete Qt4
	    $className eq 'QSharedData' || # Qt4
	    $className eq 'QPainterPath::Element' || # Qt4
	    $className eq 'QThreadStorageData' || # Qt4
	    $className eq 'QVFbHeader' || # Qt4
	    $className eq 'QStyleOptionQ3DockWindow' || # Qt4
	    $className eq 'QStyleOptionQ3ListView' || # Qt4
	    $className eq 'QStyleOptionQ3ListViewItem' || # Qt4
	    $className eq 'QStyleOptionQ3ListView' || # Qt4
	    $className eq 'QUpdateLaterEvent' || # Qt4
	    $className eq 'QVFbKeyData' || # Qt4
	    $className eq 'QVariant::Handler' || # Qt4
	    $className eq 'QVariant::PrivateShared' || # Qt4
	    $className eq 'QVectorData' || # Qt4
	    $className eq 'QWidgetData' || # Qt4
	    $className eq 'QThread' || # Qt4
		$className eq 'QThreadStorage' || # Qt4
		$className eq 'QMutex' || # Qt4
		$className eq 'QMutexLocker' || # Qt4
		$className eq 'QSemaphore' || # Qt4
		$className eq 'QWaitCondition' || # Qt4
		$className eq 'QReadWriteLock' || # Qt4
		$className eq 'QReadLocker' || # Qt4
		$className eq 'QX11Info' || # Qt4
		$className eq 'QWriteLocker' || 
	    $className =~ /.*Private$/ || # Ignore any classes which aren't for public consumption
	    $className =~ /.*Impl$/ ||
	    $className =~ /.*Internal.*/ ||
	    $classNode->{Deprecated} ||
	    $classNode->{NodeType} eq 'union' || # Skip unions for now, e.g. QPDevCmdParam
	    $className eq 'KImportedBookmarkMenu' || # KDE4
	    $className eq 'KUndoRedoAction' || # KDE4
	    $className eq 'KTzfileTimeZoneData' || # KDE4
	    $className eq 'KUndoRedoAction' # KDE4
	  ) {
	    print STDERR "Skipping $className\n" if ($debug);
	    print STDERR "Skipping union $className\n" if ( $classNode->{NodeType} eq 'union');
	    $skippedClasses{$className} = 1;
	    delete $classNode->{Compound}; # Cheat, to get it excluded from Iter::LocalCompounds
	    return;
	}
	
	my $signalCount = 0;
	my $eventHandlerCount = 0;
	my $defaultConstructor = 'none'; #  none, public, protected or private. 'none' will become 'public'.
	my $constructorCount = 0; # total count of _all_ ctors
	# If there are ctors, we need at least one public/protected one to instanciate the class
	my $hasPublicProtectedConstructor = 0;
	# We need a public dtor to destroy the object --- ### aren't protected dtors ok too ??
	my $hasPublicDestructor = 1; # by default all classes have a public dtor!
	#my $hasVirtualDestructor = 0;
	my $hasDestructor = 0;
	my $hasPrivatePureVirtual = 0;
	my $hasCopyConstructor = 0;
	my $hasPrivateCopyConstructor = 0;
	# Note: no need for hasPureVirtuals. $classNode{Pure} has that.
	
	# Hack to fix up KLed constructors in KDE 3.1
	my $kledAmbiguousConstructor = undef;

        my $doPrivate = $main::doPrivate;
	$main::doPrivate = 1;
	# Look at each class member (looking for methods and enums in particular)
	Iter::MembersByType ( $classNode, undef,
		sub {

	my( $classNode, $m ) = @_;
	my $name = $m->{astNodeName};

	if( $m->{NodeType} eq "method" ) {
	    if ( $m->{ReturnType} eq 'typedef' # QFile's EncoderFn/DecoderFn callback, very badly parsed
	       ) {
		$m->{NodeType} = 'deleted';
		next;
	    }

	    print STDERR "preParseClass: looking at $className\::$name  $m->{Params}\n" if ($debug);
	    
		if ( $name eq $classNode->{astNodeName} ) {
		if ( $m->{ReturnType} =~ /~/  ) {
		    # A destructor
		    $hasPublicDestructor = 0 if $m->{Access} ne 'public';
		    #$hasVirtualDestructor = 1 if ( $m->{Flags} =~ "v" && $m->{Access} ne 'private' );
		    $hasDestructor = 1;
		} else {
		    # A constructor
		    $constructorCount++;
		    $defaultConstructor = $m->{Access} if ( $m->{Params} eq '' );
		    $hasPublicProtectedConstructor = 1 if ( $m->{Access} ne 'private' );

		    # Copy constructor?
		    if ( $#{$m->{ParamList}} == 0 ) {
			my $theArgType = @{$m->{ParamList}}[0]->{ArgType};
                        (my $classNameWithoutNS = $className) =~ s/^.*:://;
			if ($theArgType =~ /$classNameWithoutNS\s*\&/) {
			    $hasCopyConstructor = 1;
				$m->{Flags} .= "x";
			    $hasPrivateCopyConstructor = 1 if ( $m->{Access} eq 'private' );
			}
		    }
		    # Hack the return type for constructors, since constructors return an object pointer
		    $m->{ReturnType} = $className."*";
		}
	    }

	    if ( $name =~ /~$classNode->{astNodeName}/ && $m->{Access} ne "private" ) { # not used
		$hasPublicDestructor = 0 if $m->{Access} ne 'public';
		#$hasVirtualDestructor = 1 if ( $m->{Flags} =~ "v" );
		$hasDestructor = 1;
	    }

	    if ( $m->{Flags} =~ "p" && $m->{Access} =~ /private/ ) {
                $hasPrivatePureVirtual = 1; # ouch, can't inherit from that one
	    }

	    # All we want from private methods is to check for virtuals, nothing else
	    next if ( $m->{Access} =~ /private/ );
		# Don't generate code for deprecated methods, 
		# or where the code won't compile/link for obscure reasons. Or even obvious reasons..
		if ( ($classNode->{astNodeName} eq 'KCharSelectTable' and $name eq 'paintCell')
			# KDE4
			|| ($name eq 'operator<<' and $m->{ParamList}[0]->{ArgType} =~ /QDataStream/ and $m->{ParamList}[1]->{ArgType} =~ /KDateTime::Spec/ )
			|| ($name eq 'operator>>' and $m->{ParamList}[0]->{ArgType} =~ /QDataStream/ and $m->{ParamList}[1]->{ArgType} =~ /KDateTime::Spec/ )
                        || ($name eq 'operator<<' and $m->{ParamList}[0]->{ArgType} =~ /QDataStream/ and $m->{ParamList}[1]->{ArgType} =~ /const KDateTime/ )
                        || ($name eq 'operator>>' and $m->{ParamList}[0]->{ArgType} =~ /QDataStream/ and $m->{ParamList}[1]->{ArgType} =~ /KDateTime/ )
			|| ($classNode->{astNodeName} eq 'TextEvent' and $name eq 'data')
			|| ($classNode->{astNodeName} eq 'KApplication' and $name eq 'startKdeinit')
			|| ($classNode->{astNodeName} eq 'Slave' and $name eq 'Slave')
			|| ($classNode->{astNodeName} eq 'KIcon' and $name eq 'setOverlays')
			|| ($classNode->{astNodeName} eq 'KResolver' and $name eq 'setError')
			|| ($classNode->{astNodeName} eq 'Entry' and $name eq 'setCompatibility')
			|| ($classNode->{astNodeName} eq 'KTimeZone' and $name eq 'source')
			|| ($classNode->{astNodeName} eq 'KTzfileTimeZoneSource' and $name eq 'location')
			|| ($classNode->{astNodeName} eq 'Wallet' and $name eq 'Wallet')
			# end KDE4
			|| ($classNode->{astNodeName} eq 'KAnimWidget' and $name eq 'KAnimWidget' and @{$m->{ParamList}} == 2)
			|| ($classNode->{astNodeName} eq 'KCModuleLoader' and $name eq 'errorModule')
			|| ($classNode->{astNodeName} eq 'KDCOPActionProxy' and $name eq 'actions')
			|| ($classNode->{astNodeName} eq 'KEditToolbarWidget' and $name eq 'insertActive')
			|| ($classNode->{astNodeName} eq 'KEditToolbarWidget' and $name eq 'removeActive')
			|| ($classNode->{astNodeName} eq 'KEditToolbarWidget' and $name eq 'moveActive')
			|| ($classNode->{astNodeName} eq 'KFileDialog' and $name eq 'addDirEntry')
			|| ($classNode->{astNodeName} eq 'KFileDialog' and $name eq 'getDirEntry')
			|| ($classNode->{astNodeName} eq 'KFileItem' and $name eq 'extraData')
			|| ($classNode->{astNodeName} eq 'KFileView' and $name eq 'selectionMode')
			|| ($classNode->{astNodeName} eq 'KFind' and $name eq 'KFind' and @{$m->{ParamList}} == 4)
			|| ($classNode->{astNodeName} eq 'KGlobalAccel' and $name eq 'setEnabled')
			|| ($classNode->{astNodeName} eq 'KCharsets' and $name eq 'encodingsForLanguage')
			|| ($classNode->{astNodeName} eq 'KInputDialog' and $name eq 'getInteger')
			|| ($classNode->{astNodeName} eq 'SlaveBase' and $name eq 'checkCachedAuthentication')
			|| ($classNode->{astNodeName} eq 'SlaveBase' and $name eq 'cacheAuthentication')
			|| ($classNode->{astNodeName} eq 'KInputDialog' and $name eq 'getDouble')
			|| ($classNode->{astNodeName} eq 'KToolBar' and $name eq 'enable')
			|| ($classNode->{astNodeName} eq 'KToolBar' and $name eq 'changeEvent')
			|| ($classNode->{astNodeName} eq 'KAccel' and $name eq 'insert' and @{$m->{ParamList}} == 2)
			|| ($classNode->{astNodeName} eq 'KAccel' and $name eq 'autoupdate')
			|| ($classNode->{astNodeName} eq 'KAccel' and $name eq 'getAutoUpdate')
			|| ($classNode->{astNodeName} eq 'KAction' and $name eq 'activated')
			|| ($classNode->{astNodeName} eq 'KAction' and $name eq 'actionOfType')
			|| ($classNode->{astNodeName} eq 'KAction' and $name eq 'actionsOfType')
			|| ($classNode->{astNodeName} eq 'KActionCollection' and $name eq 'add')
			|| ($classNode->{astNodeName} eq 'KStdAccel' and $name eq 'insert')
			|| ($classNode->{astNodeName} eq 'KBookmarkMenu' and $name eq 'invalid')
			|| ($classNode->{astNodeName} eq 'KCharsets' and $name eq 'languages')
			|| ($classNode->{astNodeName} eq 'KCombiView' and $name eq 'setDropOptions')
			|| ($classNode->{astNodeName} eq 'KDialogButtonBox' and $name eq 'using')
			|| ($classNode->{astNodeName} eq 'KFileMetaInfoItem' and $name eq 'unit')
			|| ($classNode->{astNodeName} eq 'KInstance' and $name eq 'charsets')
			|| ($classNode->{astNodeName} eq 'KInstance' and $name eq 'KInstance' and $m->{Access} =~ /protected/)
			|| ($classNode->{astNodeName} eq 'KKey' and $name eq 'isValidQt')
			|| ($classNode->{astNodeName} eq 'KKey' and $name eq 'isValidNative')
			|| ($classNode->{astNodeName} eq 'KKeySequence' and $name eq 'init')
			|| ($classNode->{astNodeName} eq 'KKeySequence' and $name eq 'setTriggerOnRelease')
			|| ($classNode->{astNodeName} eq 'KEMailSettings' and $name eq 'getExtendedSetting')
			|| ($classNode->{astNodeName} eq 'KEMailSettings' and $name eq 'setExtendedSetting')
			|| ($classNode->{astNodeName} eq 'KProtocolManager' and $name eq 'defaultConnectTimeout')
			|| ($classNode->{astNodeName} eq 'KMD4' and $name eq 'transform')
			|| ($classNode->{astNodeName} eq 'KMD5' and $name eq 'transform')
			|| ($classNode->{astNodeName} eq 'KSSLCertificate' and $name eq 'operator!=')
			|| ($classNode->{astNodeName} eq 'KSSLPKCS7' and $name eq 'validate')
			|| ($classNode->{astNodeName} eq 'KSSLPKCS7' and $name eq 'revalidate')
			|| ($classNode->{astNodeName} eq 'KSSLSession' and $name eq 'KSSLSession' and @{$m->{ParamList}} == 1)
			|| ($classNode->{astNodeName} eq 'KSimpleFileFilter' and $name eq 'nameFilters')
			|| ($classNode->{astNodeName} eq 'KTabWidget' and $name eq 'isTabReorderingEnabled')
			|| ($classNode->{astNodeName} eq 'KTabWidget' and $name eq 'hoverCloseButton')
			|| ($classNode->{astNodeName} eq 'KTabWidget' and $name eq 'hoverCloseButtonDelayed')
			|| ($classNode->{astNodeName} eq 'KTar' and $name eq 'writeFile_impl')
			|| ($classNode->{astNodeName} eq 'KIO' and $name eq 'buildHTMLErrorString')
			|| ($classNode->{astNodeName} eq 'KIO' and $name eq 'pasteClipboard')
			|| ($classNode->{astNodeName} eq 'KIO' and $name eq 'pasteData')
			|| ($classNode->{astNodeName} eq 'KIO' and $name eq 'pasteDataAsync')
			|| ($classNode->{astNodeName} eq 'KIO' and $name eq 'isClipboardEmpty')
			|| ($classNode->{astNodeName} eq 'KIO::NetRC' and $name eq 'lookup')
			|| ($classNode->{astNodeName} eq 'DCOPRef' and $name eq 'callExt')
			|| ($classNode->{astNodeName} eq 'DCOPRef' and $name eq 'call')
			|| ($classNode->{astNodeName} eq 'DCOPRef' and $name eq 'send')
			|| ($classNode->{astNodeName} eq 'DOM' and $name eq 'operator<<') # Avoid kdbgstream debugging method
			|| ($name eq 'initgroups')
			|| ($name eq 'qInitJpegIO' and $main::qt4)
			|| ($name eq 'qInitPngIO' and $main::qt4)
			|| ($name eq 'qt_metacast' and $main::qt4)
			|| ($name eq 'virtual_hook')
			|| ($name eq 'handle')
			|| ($name eq 'qHash')
			|| ($classNode->{astNodeName} eq 'QwtThermo' and $name eq 'setFillBrush')
			|| ($classNode->{astNodeName} eq 'QwtThermo' and $name eq 'fillBrush')
			|| ($classNode->{astNodeName} eq 'QwtThermo' and $name eq 'setFillColor')
			|| ($classNode->{astNodeName} eq 'QwtThermo' and $name eq 'fillColor')
			|| ($classNode->{astNodeName} eq 'QwtThermo' and $name eq 'setAlarmBrush')
			|| ($classNode->{astNodeName} eq 'QwtThermo' and $name eq 'alarmBrush')
			|| ($classNode->{astNodeName} eq 'QwtThermo' and $name eq 'setAlarmColor')
			|| ($classNode->{astNodeName} eq 'QwtThermo' and $name eq 'alarmColor')
			|| ($classNode->{astNodeName} eq 'QwtWheel' and $name eq 'getScrollMode')
			|| ($classNode->{astNodeName} eq 'QwtSpline' and $name eq 'points')
			|| ($classNode->{astNodeName} eq 'QwtPlot' and $name eq 'drawItems')
			|| ($classNode->{astNodeName} eq 'QwtPlot' and $name eq 'printCanvas')
			|| ($classNode->{astNodeName} eq 'QwtPlot' and $name eq 'drawItems')
			|| ($classNode->{astNodeName} eq 'QwtPlot' and $name eq 'setCanvasBackground')
			|| ($classNode->{astNodeName} eq 'QwtPlot' and $name eq 'canvasBackground')
			|| ($classNode->{astNodeName} eq 'QwtPlotLayout' and $name eq 'expandLineBreaks')
			|| ($classNode->{astNodeName} eq 'QwtPlotLayout' and $name eq 'alignScales')
			|| ($classNode->{astNodeName} eq 'QwtData' and $name eq 'operator=')
			|| ($classNode->{astNodeName} eq 'QwtScaleTransformation' and $name eq 'double')
			|| ($classNode->{astNodeName} eq 'QwtScaleDiv' and $name eq 'QwtScaleDiv' and @{$m->{ParamList}} > 0)
			# Obsolete
			|| ($classNode->{astNodeName} eq 'QTextStream' and $name eq 'QTextStream'
					and @{$m->{ParamList}} == 2 and $m->{ParamList}[0]->{ArgType} eq 'QString&')
			
			# Various methods to skip in Qt/E (Qt 2.3.x)
			|| ($main::qt_embedded
				&& ( ($classNode->{astNodeName} eq 'QUriDrag' and $name =~ /^decode$|decodeLocalFiles|decodeToUnicodeUris/)
				|| ($classNode->{astNodeName} eq 'QApplication' and $name =~ /^qwsSetCustomColors|^setArgs$|^winMouseButtonUp|^winFocus|^winMouseButtonUP$|^winVersion$/)
				|| ($classNode->{astNodeName} eq 'QPrinter' and $name =~ /^setIdle$|^setActive$/)
				|| ($classNode->{astNodeName} eq 'QDragObject' and $name eq 'dragLink')
				|| ($classNode->{astNodeName} eq 'QFont' and $name eq 'qwsRenderToDisk')
				|| ($classNode->{astNodeName} eq 'QFontInfo' and $name eq 'font')
				|| ($classNode->{astNodeName} eq 'QLineEdit' and $name eq 'getSelection')
				|| ($classNode->{astNodeName} eq 'QMainWindow' and $name eq 'toolBars')
				|| ($classNode->{astNodeName} eq 'QMovie' and $name eq 'setDisplayWidget')
				|| ($classNode->{astNodeName} eq 'QMetaObject' and $name =~ /^new_metaenum_item$|^new_metaaccess$/)
				|| ($classNode->{astNodeName} eq 'QPainter' and $name eq 'pos')
				|| ($classNode->{astNodeName} eq 'QPixmap' and $name =~ /^allocCell$|^clut$|^freeCell|^hbm|^isMultiCellPixmap|^multiCellPixmap|^multiCellBitmap|^multiCellHandle|^multiCellOffset|^numCols/)
				|| ($name eq 'handle')
				|| ($name eq 'resetInputContext')
				|| ($name eq 'propagateUpdates')
				|| ($name eq 'bytesPerLine')
				|| ($name eq 'scanLine')
				|| ($name eq 'hPal')
				|| ($name eq 'copyX11Data')
				|| ($name eq 'getX11Data')
				|| ($name eq 'setX11Data')
				|| ($name eq 'realizePal')
				|| ($name eq 'qwsDisplay')
				|| ($name eq 'fixport')
				|| ($name eq 'hack_strrchr')
				|| ($name eq 'hack_strchr')
				|| ($name eq 'hack_strstr') ) )
						
			# Assume only Qt classes have tr() and trUtf8() in their Q_OBJECT macro
			|| ($classNode->{astNodeName} !~ /^Q/ and $name eq 'tr')
			|| ($classNode->{astNodeName} !~ /^Q/ and $name eq 'trUtf8')

			|| ($main::qt4
				&& ( ($classNode->{astNodeName} eq 'QWidgetListItem' and $name eq 'operator=')
				|| ($classNode->{astNodeName} eq 'QColormap' and $name eq 'operator=')
				|| ($classNode->{astNodeName} eq 'QGraphicsLineItem' and $name eq 'QGraphicsLineItem' and $#{$m->{ParamList}} == 5)
				|| ($classNode->{astNodeName} eq 'QGraphicsEllipseItem' and $name eq 'QGraphicsEllipseItem' and $#{$m->{ParamList}} == 5)
				|| ($classNode->{astNodeName} eq 'QListWidget' and $name eq 'setItemPosition')
				|| ($classNode->{astNodeName} eq 'QFontMetricsF' and $name eq 'operator=')
				|| ($classNode->{astNodeName} eq 'QFontMetricsF' and $name eq 'QFontMetricsF' 
					and $#{$m->{ParamList}} == 0 && $m->{ParamList}[0]->{ArgType} eq 'const QFontMetrics&')
				|| ($classNode->{astNodeName} eq 'QAbstractItemDelegate' and $name eq 'QAbstractItemDelegate' 
					and $#{$m->{ParamList}} == 0 && $m->{ParamList}[0]->{ArgType} eq 'const QAbstractItemDelegate&')
				|| ($classNode->{astNodeName} eq 'QHttp' and $name eq 'supportedOperations')
				|| ($classNode->{astNodeName} eq 'QPrinter' and $name eq 'printRange')
				|| ($classNode->{astNodeName} eq 'QPrinter' and $name eq 'setPrintRange')
				|| ($classNode->{astNodeName} eq 'QRectF' and $name eq 'setX')
				|| ($classNode->{astNodeName} eq 'QRectF' and $name eq 'setY')
				|| ($classNode->{astNodeName} eq 'QTextObject' and $name eq 'formatType')
				|| ($classNode->{astNodeName} eq 'QUrl' and $name eq 'QUrl'
					and $#{$m->{ParamList}} == 0 && $m->{ParamList}[0]->{ArgType} eq 'QUrlPrivate&')
				|| ($classNode->{astNodeName} eq 'QGlobalSpace' and $name eq 'operator<<' and $m->{ParamList}[0]->{ArgType} =~ /QDebug/)
				|| ($classNode->{astNodeName} eq 'QGlobalSpace' and $name eq 'qDebug')
				|| ($classNode->{astNodeName} eq 'QGlobalSpace' and $name eq 'qWarning')
				|| ($classNode->{astNodeName} eq 'QGlobalSpace' and $name eq 'qCritical')
				|| ($classNode->{astNodeName} eq 'QGlobalSpace' and $#{$m->{ParamList}} > 0 and $name =~ /operator/ and $m->{ParamList}[1]->{ArgType} =~ /QVariant::Type/)
				|| ($#{$m->{ParamList}} > 0 and $m->{ParamList}[0]->{ArgType} =~ /Private/)
				|| ($classNode->{astNodeName} eq 'QScrollArea' and $name eq 'alignment')
				|| ($classNode->{astNodeName} eq 'QScrollArea' and $name eq 'setAlignment')
				|| ($classNode->{astNodeName} eq 'QDBusConnection' and $name eq 'findInterface' and 
					$m->{ReturnType} =~ /</ )
				|| ($classNode->{astNodeName} eq 'QDBusBusService' and $name eq 'RequestName')
				|| ($classNode->{astNodeName} eq 'QDBusBusService' and $name eq 'requestName')
				|| ($classNode->{astNodeName} eq 'QGLFormat' and $name eq 'openGLVersionFlags')
				|| ($classNode->{astNodeName} eq 'QAbstractUndoItem' and $name eq '~QAbstractUndoItem')
				|| ($classNode->{astNodeName} eq 'QApplication' and $name eq 'setKeypadNavigationEnabled')
				|| ($classNode->{astNodeName} eq 'QApplication' and $name eq 'keypadNavigationEnabled')
				|| ($name eq 'qDBusMetaTypeId')
				|| ($m->{ReturnType} =~ /template/)
				|| ($m->{ReturnType} =~ /QT3_SUPPORT/) ) )

			|| $m->{Deprecated} ) {
		    $m->{NodeType} = 'deleted';
			next;
		}

		# QLayout::setGeometry() is marked as pure virtual in the header, but actually has
		# an implementation, so special case it.
		if ($main::qt4 and $classNode->{astNodeName} eq 'QLayout' and $name eq 'setGeometry') {
			$m->{Flags} =~ s/p//;
		}

		# Hack for fixing up KDE 3.1 KLed where the no arg constructor was ambiguous
		if ($classNode->{astNodeName} eq 'KLed' and $name eq 'KLed' && $#{$m->{ParamList}} > 0) {
			if ($m->{ParamList}[0]->{ArgType} =~ /QColor/ && defined $m->{ParamList}[0]->{DefaultValue}) {
				$m->{ParamList}[0]->{DefaultValue} = undef;
				if (defined $kledAmbiguousConstructor) {
					$kledAmbiguousConstructor->{ParamList}[0]->{DefaultValue} = undef;
					$kledAmbiguousConstructor->{FirstDefaultParam} = 1;
				}
			} else {
				$kledAmbiguousConstructor = $m;
			}
		}

		# cut the last arguments in size(), boundingRect(), both methods was ambiguous
		if ($classNode->{astNodeName} eq 'QFontMetrics' and $name eq 'boundingRect' && $#{$m->{ParamList}} == 7) {
			if ($m->{ParamList}[7]->{ArgType} =~ /int/ && defined $m->{ParamList}[7]->{DefaultValue}) {
			    pop(@{$m->{ParamList}});
			    $#{$m->{ParamList}}--;
			    $m->{Params} =~ s/int \*tabarray\=0//;
			}
		}

		if ($classNode->{astNodeName} eq 'QFontMetrics' and $name eq 'size' && $#{$m->{ParamList}} == 3) {
			if ($m->{ParamList}[3]->{ArgType} =~ /int/ && defined $m->{ParamList}[3]->{DefaultValue}) {
			    pop(@{$m->{ParamList}});
			    $#{$m->{ParamList}}--;
			    $m->{Params} =~ s/int \*tabarray\=0//;
			}
		}

		
	    my $argId = 0;
	    my $firstDefaultParam;
	    foreach my $arg ( @{$m->{ParamList}} ) {
		# Look for first param with a default value
		if ( defined $arg->{DefaultValue} && !defined $firstDefaultParam ) {
		    $firstDefaultParam = $argId;
		}

		if ( $arg->{ArgType} eq '...' # refuse a method with variable arguments
		     or $arg->{ArgType} eq 'image_io_handler' # QImage's callback
		     or $arg->{ArgType} eq 'DecoderFn' # QFile's callback
		     or $arg->{ArgType} eq 'EncoderFn' # QFile's callback
		     or $arg->{ArgType} =~ /bool \(\*\)\(QObject/ # QMetaObject's ctor
		     or $arg->{ArgType} eq 'QtStaticMetaObjectFunction' # QMetaObjectCleanUp's ctor with func pointer
		     or $arg->{ArgType} eq 'const QTextItem&' # ref to a private class in 3.2.0b1
		     or $arg->{ArgType} eq 'FILE*' # won't be able to handle that I think
		     or $arg->{ArgType} eq 'const KKeyNative&' #
		     or $arg->{ArgType} =~ /Node\s*\*/ #
		) {
		    $m->{NodeType} = 'deleted';
		}
		else
		{
		    # Resolve type in full, e.g. for QSessionManager::RestartHint
		    # (x_QSessionManager doesn't inherit QSessionManager)
		    $arg->{ArgType} = kalyptusDataDict::resolveType($arg->{ArgType}, $classNode, $rootnode);
		    registerType( $arg->{ArgType} );
		    $argId++;
		}
	    }
	    $m->AddProp( "FirstDefaultParam", $firstDefaultParam );
	    $m->{ReturnType} = kalyptusDataDict::resolveType($m->{ReturnType}, $classNode, $rootnode) if ($m->{ReturnType});
	    registerType( $m->{ReturnType} );
	}
	elsif( $m->{NodeType} eq "enum" ) {
	    my $fullEnumName = $className."::".$m->{astNodeName};
		
		if ( ($fullEnumName eq 'KMimeType::Format' and $name eq 'compression')
				|| $m->{Deprecated} ) {
		    $m->{NodeType} = 'deleted';
			next;
		}
	    
		$classNode->{enumerations}{$m->{astNodeName}} = $fullEnumName
		if $m->{astNodeName} and $m->{Access} ne 'private';

	    # Define a type for this enum
	    registerType( $fullEnumName );

	    # Remember that it's an enum
	    findTypeEntry( $fullEnumName )->{isEnum} = 1;

	    #print STDERR "$fullEnumName is an enum\n";
 	}
	elsif( $m->{NodeType} eq 'var' ) {
		if (	($classNode->{astNodeName} eq 'QUuid' and $name eq 'data4')
				|| ($name eq 'd')
				|| ($classNode->{astNodeName} eq 'QObject' and $name eq 'staticMetaObject')
				|| ($classNode->{astNodeName} eq 'SlaveBase' and $name eq 'mIncomingMetaData')
				|| ($classNode->{astNodeName} eq 'SlaveBase' and $name eq 'mOutgoingMetaData') ) 
		{
			$m->{NodeType} = 'deleted';
			next;
		}

	    my $varType = $m->{Type};
		$varType =~ s/const\s+(.*)\s*&/$1/;
		$varType =~ s/^\s*//;
		$varType =~ s/\s*$//;
		$varType =~ s/static\s+//;

		if ( $m->{Flags} =~ "s" ) {
			# We are interested in public static vars, like QColor::blue
			if ( $m->{Access} ne 'private'
				&& $className."::".$m->{astNodeName} ne "KSpell::modalListText" )
			{
				print STDERR "var: $m->{astNodeName} '$varType'\n" if ($debug);

				# Register the type
				registerType( $varType );
			} else {
				$m->{NodeType} = 'deleted';
			}
		} elsif ($m->{Access} eq 'public') {
			# Add a setter method for a public instance variable
			my $setMethod = $name;
			if ($setMethod =~ /^(\w)(.*)/) {
				my $ch = $1;
				$ch =~ tr/a-z/A-Z/;
				$setMethod = "set$ch$2";
			}
			my $node = Ast::New( $setMethod );
			$node->AddProp( "NodeType", "method" );
			# Flags of "=" for a setter method
			$node->AddProp( "Flags", "=" );
			$node->AddProp( "ReturnType", "void" );
			$node->AddProp( "Params", $varType );

			my $param = Ast::New( 1 );
			$param->AddProp( "NodeType", "param" );
			$param->AddProp( "ArgType", $varType );
			$node->AddPropList( "ParamList", $param );

			kdocAstUtil::attachChild( $classNode, $node );

			# Register the type
			registerType( $varType );
		} else {
			$m->{NodeType} = 'deleted';
		}
	}
		},
		undef
	);
	$main::doPrivate = $doPrivate;

	print STDERR "$className: ctor count: $constructorCount, hasPublicProtectedConstructor: $hasPublicProtectedConstructor, hasCopyConstructor: $hasCopyConstructor:, defaultConstructor: $defaultConstructor, hasPublicDestructor: $hasPublicDestructor, hasPrivatePureVirtual:$hasPrivatePureVirtual\n" if ($debug);

	my $isGlobalSpace = ($className eq $main::globalSpaceClassName);

	# Note that if the class has _no_ constructor, the default ctor applies. Let's even generate it.
	if ( !$constructorCount && $defaultConstructor eq 'none' 
		&& !$hasPrivatePureVirtual && !$isGlobalSpace && $classNode->{NodeType} ne 'namespace' ) {
	    # Create a method node for the constructor
	    my $methodNode = Ast::New( $classNode->{astNodeName} );
	    $methodNode->AddProp( "NodeType", "method" );
	    $methodNode->AddProp( "Flags", "" );
	    $methodNode->AddProp( "Params", "" );
            $methodNode->AddProp( "ParamList", [] );
	    kdocAstUtil::attachChild( $classNode, $methodNode );

	    # Hack the return type for constructors, since constructors return an object pointer
	    $methodNode->AddProp( "ReturnType", $className."*" );
	    registerType( $className."*" );
	    $methodNode->AddProp( "Access", "public" ); # after attachChild
	    $defaultConstructor = 'public';
	    $hasPublicProtectedConstructor = 1;
	}

	# Also, if the class has no explicit destructor, generate a default one.
	if ( !$hasDestructor && !$hasPrivatePureVirtual && !$isGlobalSpace && $classNode->{NodeType} ne 'namespace' ) {
	    my $methodNode = Ast::New( "$classNode->{astNodeName}" );
	    $methodNode->AddProp( "NodeType", "method" );
	    $methodNode->AddProp( "Flags", "" );
	    $methodNode->AddProp( "Params", "" );
	    $methodNode->AddProp( "ParamList", [] );
	    kdocAstUtil::attachChild( $classNode, $methodNode );

	    $methodNode->AddProp( "ReturnType", "~" );
	    $methodNode->AddProp( "Access", "public" );
	}

	# If we have a private pure virtual, then the class can't be instanciated (e.g. QCanvasItem)
	# Same if the class has only private constructors (e.g. QInputDialog)
	$classNode->AddProp( "CanBeInstanciated", $hasPublicProtectedConstructor && !$hasPrivatePureVirtual );

	# We will derive from the class only if it has public or protected constructors.
	# (_Even_ if it has pure virtuals. But in that case the x_ class can't be instantiated either.)
	$classNode->AddProp( "BindingDerives", $hasPublicProtectedConstructor );

	# We need a public dtor to destroy the object --- ### aren't protected dtors ok too ??
	$classNode->AddProp( "HasPublicDestructor", $hasPublicDestructor );

	# Hack for QAsyncIO. We don't implement the "if a class has no explicit copy ctor,
	# then all of its member variables must be copiable, otherwise the class isn't copiable".
	$hasPrivateCopyConstructor = 1 if ( $className eq 'QAsyncIO' );

	# Remember if this class can't be copied - it means all its descendants can't either
	$classNode->AddProp( "CanBeCopied", !$hasPrivateCopyConstructor );
	$classNode->AddProp( "HasCopyConstructor", $hasCopyConstructor );
}


sub propagateCanBeCopied($)
{
	my $classNode = shift;
	my $className = join( "::", kdocAstUtil::heritage($classNode) );
	my @super = superclass_list($classNode);
	# A class can only be copied if none of its ancestors have a private copy ctor.
	for my $s (@super) {
	    if (!$s->{CanBeCopied}) {
		$classNode->{CanBeCopied} = 0;
		print STDERR "$classNode->{astNodeName} cannot be copied\n" if ($debug);
		last;
	    }
	}
	# If the class has no explicit copy constructor, and it can be copied,
	# generate the copy constructor.
	if ( !$classNode->{HasCopyConstructor} && $classNode->{CanBeCopied} && $classNode->{CanBeInstanciated} ) {
	    my $methodNode = Ast::New( "$classNode->{astNodeName}" );
	    $methodNode->AddProp( "NodeType", "method" );
	    $methodNode->AddProp( "Flags", "ix" ); # Only for internal use in marshallers
	    my $argType = "const ".$className."&";
	    registerType( $argType );
	    $methodNode->AddProp( "Params", $argType );
	    # The param node
		my $node = Ast::New( 1 ); # let's make the arg index the node "name"
		$node->AddProp( "NodeType", "param" );
		$node->AddProp( "ArgType", $argType );
		$methodNode->AddPropList( "ParamList", $node );
	    kdocAstUtil::attachChild( $classNode, $methodNode );

	    # Hack the return type for constructors, since constructors return an object pointer
	    $methodNode->AddProp( "ReturnType", $className."*" );
	    registerType( $className."*" );
	    $methodNode->AddProp( "Access", "public" ); # after attachChild
	}

	# Prepare the {case} dict for the class
	prepareCaseDict( $classNode );
}

=head2 writeClassDoc

	Called by writeDoc for each series of classes to be written out

=cut

BEGIN {

my $fhn =1; # static

  sub writeClassDoc
  {
	my $nodelist = shift;
        my $file = "$outputdir/x_${fhn}.cpp";
        open( my $fh, ">$file" ) || die "Couldn't create $file\n";

	print $fh "//Auto-generated by $0. DO NOT EDIT.\n";
 	print $fh "#include <smoke.h>\n";
 	print $fh "#include <${libname}_smoke.h>\n";
	
        my @code;
        for my $node ( @$nodelist )
        {
            push @code, [generateAllMethods( $node )]
        }
        my %includes;
        map { for my $incl (keys %{$_->[2]}){ $includes{$incl}++ } } @code;

	# Hack - some Qt/KDE headers need other headers included, but omit suitable #includes
	if (defined $includes{"qregexp.h"} || defined $includes{"qcstring.h"}) {
	    print $fh "#include <qregexp.h>\n";
		delete $includes{"qregexp.h"};
	}
	if (defined $includes{"qmime.h"} || defined $includes{"qmimedata.h"}) {
	    print $fh "#include <qurl.h>\n";
		delete $includes{"qurl.h"};
	}
	if (defined $includes{"kshortcut.h"}) {
	    print $fh "#include <kshortcut.h>\n";
		delete $includes{"kshortcut.h"};
	} 
	if (defined $includes{"kshortcutlist.h"}) {
	    print $fh "#include <kconfigbase.h>\n";
	    print $fh "#include <kshortcutlist.h>\n";
		delete $includes{"kconfigbase.h"};
		delete $includes{"kshortcutlist.h"};
	}
	if (defined $includes{"kaction.h"}) {
	    print $fh "#include <kaction.h>\n";
		delete $includes{"kaction.h"};
	}
	foreach my $incl (keys %includes) {
	    die if $incl eq '';
	    print $fh "#include <$incl>\n";
	}	
	print $fh "\n";
        for my $c( 0..$#code )
        {
           my ($methodCode, $switchCode, $incl) = @{ $code[$c] };
           my $node = $$nodelist[$c];
           my $className = join( "::", kdocAstUtil::heritage($node) );
           my $legacyClassName = join( "__", kdocAstUtil::heritage($node) );
           print $fh "class x_$legacyClassName ";
           print $fh ": public $className " if $node->{BindingDerives};
           print $fh "{\n";
           print $fh $methodCode;
           print $fh "};\n";
	   if(keys %{$node->{enumerations}}) {
	        print $fh "void xenum_${legacyClassName}(Smoke::EnumOperation xop, Smoke::Index xtype, void *&xdata, long &xvalue) {\n";
	        print $fh "    x_${legacyClassName}\::xenum_operation(xop, xtype, xdata, xvalue);\n";
	        print $fh "}\n";
	   }
	   print $fh "void xcall_${legacyClassName}(Smoke::Index xi, void *obj, Smoke::Stack args) {\n";
	   print $fh $switchCode;
	   print $fh "}\n\n";
        }
	#if ( $className =~ /^(QBrush|QColor|QCursor|QFont|QImage|QPalette|QPixmap|QPoint|QPointArray|QRect|QRegion|QSize|QWMatrix)$/ ) {
	#	print XCPPFILE "    const char *{serial} operator << () const : pig_serialize(\$this);\n";
	#	print XCPPFILE "    void operator >> (const char *{serial}) : pig_deserialize(\$this, \$1);\n";
	#}

	close $fh;
        $fhn++
  }

}

# Generate the prototypes for a method (one per arg with a default value)
# Helper for makeprotos
sub iterproto($$$$$) {
    my $classidx = shift; # to check if a class exists
    my $method = shift;
    my $proto = shift;
    my $idx = shift;
    my $protolist = shift;

    my $argcnt = scalar @{ $method->{ParamList} } - 1;
    if($idx > $argcnt) {
	push @$protolist, $proto;
	return;
    }
    if(defined $method->{FirstDefaultParam} and $method->{FirstDefaultParam} <= $idx) {
	push @$protolist, $proto;
    }

    my $arg = $method->{ParamList}[$idx]->{ArgType};

    my $typeEntry = findTypeEntry( $arg );
    my $realType = $typeEntry->{realType};

    # A scalar ?
    $arg =~ s/\bconst\b//g;
    $arg =~ s/\s+//g;
    if($typeEntry->{isEnum} || $allTypes{$realType}{isEnum} || exists $typeunion{$realType} || exists $mungedTypeMap{$arg})
    {
	my $id = '$'; # a 'scalar
	$id = '?' if $arg =~ /[*&]{2}/;
	$id = $mungedTypeMap{$arg} if exists $mungedTypeMap{$arg};
	iterproto($classidx, $method, $proto . $id, $idx + 1, $protolist);
	return;
    }

    # A class ?
    if(exists $classidx->{$realType}) {
	iterproto($classidx, $method, $proto . '#', $idx + 1, $protolist);
	return;
    }

    # A non-scalar (reference to array or hash, undef)
    iterproto($classidx, $method, $proto . '?', $idx + 1, $protolist);
    return;
}

# Generate the prototypes for a method (one per arg with a default value)
sub makeprotos($$$) {
    my $classidx = shift;
    my $method = shift;
    my $protolist = shift;
    iterproto($classidx, $method, $method->{astNodeName}, 0, $protolist);
}

# Return the string containing the signature for this method (without return type).
# If the 2nd arg is not the size of $m->{ParamList}, this method returns a
# partial signature (this is used to handle default values).
sub methodSignature($$) {
    my $method = shift;
    my $last = shift;
    my $sig = $method->{astNodeName};
    my @argTypeList;
    my $argId = 0;
    foreach my $arg ( @{$method->{ParamList}} ) {
	last if $argId > $last;
	push @argTypeList, $arg->{ArgType};
	$argId++;
    }
    $sig .= "(". join(", ",@argTypeList) .")";
    $sig .= " const" if $method->{Flags} =~ "c";
    return $sig;
}

sub coerce_type($$$$) {
    #my $m = shift;
    my $union = shift;
    my $var = shift;
    my $type = shift;
    my $new = shift; # 1 if this is a return value, 0 for a normal param

    my $typeEntry = findTypeEntry( $type );
    my $realType = $typeEntry->{realType};

    my $unionfield = $typeEntry->{typeId};
    die "$type" unless defined( $unionfield );
    $unionfield =~ s/t_/s_/;

    $type =~ s/\s+const$//; # for 'char* const'
    $type =~ s/\s+const\s*\*$/\*/; # for 'char* const*'

    my $code = "$union.$unionfield = ";
    if($type =~ /&$/) {
	$code .= "(void*)&$var;\n";
    } elsif($type =~ /\*$/) {
	$code .= "(void*)$var;\n";
    } else {
	if ( $unionfield eq 's_class' 
		or ( $unionfield eq 's_voidp' and $type ne 'void*' )
		or $type eq 'QString' ) { # hack
	    $type =~ s/^const\s+//;
	    if($new) {
	        $code .= "(void*)new $type($var);\n";
	    } else {
	        $code .= "(void*)&$var;\n";
	    }
	} else {
	    $code .= "$var;\n";
	}
    }

    return $code;
}

# Generate the list of args casted to their real type, e.g.
# (QObject*)x[1].s_class,(QEvent*)x[2].s_class,x[3].s_int
sub makeCastedArgList
{
    my @castedList;
    my $i = 1; # The args start at x[1]. x[0] is the return value
    my $arg;
    foreach $arg (@_) {
	my $type = $arg;
	my $cast;

	my $typeEntry = findTypeEntry( $type );
	my $unionfield = $typeEntry->{typeId};
	die "$type" unless defined( $unionfield );
	$unionfield =~ s/t_/s_/;

	$type =~ s/\s+const$//; # for 'char* const'
	$type =~ s/\s+const\s*\*$/\*/; # for 'char* const*'

	my $v .= "x[$i].$unionfield";
	if($type =~ s/&$//) {
	    $cast = "*($type *)";
	} elsif($type =~ /\*$/) {
	    $cast = "($type)";
        } elsif($type =~ /\(\*\)\s*\(/) { # function pointer ... (*)(...)
            $cast = "($type)";
	} else {
	    if ( $unionfield eq 's_class'
		or ( $unionfield eq 's_voidp' and $type ne 'void*' )
		or $type eq 'QString' ) { # hack
	        $cast = "*($type *)";
	    } else {
	        $cast = "($type)";
	    }
	}
	push @castedList, "$cast$v";
	$i++;
    }
    return @castedList;
}

# Adds the header for node $1 to be included in $2 if not already there
# Prints out debug stuff if $3
sub addIncludeForClass($$$)
{
    my ( $node, $addInclude, $debugMe ) = @_;
    my $sourcename = $node->{Source}->{astNodeName};
    if ( $sourcename !~ s!.*($headerSubdirectories)(.*)!$1$2!m ) {
    	$sourcename =~ s!.*/(.*)!$1!m;
	}
#    die "Empty source name for $node->{astNodeName}" if ( $sourcename eq '' );
    return if ( $sourcename eq '' );
    unless ( defined $addInclude->{$sourcename} ) {
	print "  Including $sourcename\n" if ($debugMe);
	$addInclude->{$sourcename} = 1;
    }
    else { print "  $sourcename already included.\n" if ($debugMe); }
}

sub checkIncludesForObject($$)
{
    my $type = shift;
    my $addInclude = shift;

    my $debugCI = 0; #$debug
    #print "checkIncludesForObject $type\n";
    $type =~ s/const\s+//;
    my $it = $type;
    if (!($it and exists $typeunion{$it}) and $type !~ /\*/
         #and $type !~ /&/  # in fact we also want refs, due to the generated code
        ) {
	$type =~ s/&//;
	print "  Detecting an object by value/ref: $type\n" if ($debugCI);
	my $node = kdocAstUtil::findRef( $rootnode, $type );
	if ($node) {
	    addIncludeForClass( $node, $addInclude, $debugCI );
	}
	else { print " No header found for $type\n" if ($debugCI); }
    }
}

sub generateVirtualMethod($$$$$)
{
    # Generating methods for $class.
    # $m: method node. $methodClass: the node of the class in which the method is really declared
    # (can be different from $class when the method comes from a super class)
    # This is important because of $allMethods, which has no entry for class::method in that case.

    my( $classNode, $signature, $m, $methodClass, $addInclude ) = @_;
    my $methodCode = '';                    # output
    my $returnType = $m->{ReturnType};
    return ('', '') if $returnType eq '~'; # skip destructors

    my $className = $classNode->{astNodeName};
    my $flags = $m->{Flags};
    my @argList = @{$m->{ParamList}};

    print "generateVirtualMethod $className: $signature  ($m->{Access})\n" if ($debug);

    # Detect objects returned by value
    checkIncludesForObject( $returnType, $addInclude ) if ($returnType ne 'void');

    # Generate a matching virtual method in the x_ class
    $methodCode .= "    virtual $returnType $m->{astNodeName}(";
    my $i = 0;
    foreach my $arg ( @argList ) {
        $methodCode .= ", " if $i++;
        $methodCode .= $arg->{ArgType};
        $methodCode .= " x$i";

	# Detect objects passed by value
	checkIncludesForObject( $arg->{ArgType}, $addInclude );
    }
    $methodCode .= ") ";
    $methodCode .= "const " if ($flags =~ "c");
    $methodCode .= "\{\n";

    # Now the code of the method
    my $this = $classNode->{BindingDerives} > 0 ? "this" : "xthis";

    $i++; # Now the number of args
    $methodCode .= "\tSmoke::StackItem x[$i];\n";
    $i = 1;
    for my $arg (@argList) {
	$methodCode .= "\t";
	$methodCode .= coerce_type("x[$i]", "x$i", $arg->{ArgType}, 0);
	$i++;
    }

    my $sig = $methodClass->{astNodeName} . "::" . $signature;
    my $idx = $allMethods{$sig};
    
	if ( ! defined $idx ) {
		my $class_name = join( "::", kdocAstUtil::heritage($methodClass) );
		$sig = $class_name . "::" . $signature;
		$idx = $allMethods{$sig};
	}
#    die "generateVirtualMethod: $className: No method found for $sig\n" if !defined $idx;

if ( !defined $idx ) {
    print "generateVirtualMethod: $className: No method found for $sig\n";
    return ('', '');
}

    if($flags =~ "p") { # pure virtual
	$methodCode .= "\t${libname}_Smoke->binding->callMethod($idx, (void*)$this, x, true /*pure virtual*/);\n";
    } else {
	$methodCode .= "\tif(${libname}_Smoke->binding->callMethod($idx, (void*)$this, x)) ";
    }

    $returnType = undef if ($returnType eq 'void');
    if($returnType) {
	my $arg = $returnType;
	my $it = applyTypeDef( $arg );
	my $cast;
	my $v = "x[0]";
	my $indent = ($flags =~ "p") ? "\t" : "";
	if($it and exists $typeunion{$it}) {
	    $v .= ".$typeunion{$it}";
	    $cast = "($arg)";
	    $methodCode .= "${indent}return $cast$v;\n";
	} else {
	    $v .= ".s_class";
	    if($arg =~ s/&//) {
		$cast = "*($arg *)";
		$methodCode .= "${indent}return $cast$v;\n";
	    } elsif($arg !~ /\*$/) {
		unless($flags =~ "p") {
		    $indent = "\t    ";
		    $methodCode .= "{\n";
		}
		# we assume it's a new thing, and handle it
		$methodCode .= "${indent}$arg *xptr = ($arg *)$v;\n";
		$methodCode .= "${indent}$arg xret(*xptr);\n";
		$methodCode .= "${indent}delete xptr;\n";
		$methodCode .= "${indent}return xret;\n";
		$methodCode .= "\t}\n" unless $flags =~ "p";
	    } else {
		$cast = "($arg)";
		$methodCode .= "${indent}return $cast$v;\n";
	    }
	}
    } else {
	$methodCode .= "\t" if $flags =~ "p";
	$methodCode .= "return;\n";
    }
    if($flags =~ "p") {
	$methodCode .= "\t// ABSTRACT\n";
	$methodCode .= "    }\n";
	return ( $methodCode );
    }
    $methodCode .= "\t";
    if($returnType) {
	$methodCode .= "return ";
    }
    $methodCode .= "$this\->$methodClass->{astNodeName}\::$m->{astNodeName}(";
    $i = 0;
    for my $arg (@argList) {
	$methodCode .= ", " if $i++;
	$methodCode .= "x$i";
    }
    $methodCode .= ");\n";
    $methodCode .= "    }\n";
    return ( $methodCode );
}

sub generateMethod($$$)
{
    my( $classNode, $m, $addInclude ) = @_;	# input
    my $methodCode = '';	# output
    my $switchCode = '';	# output

    my $name = $m->{astNodeName}; # method name
    my @heritage = kdocAstUtil::heritage($classNode);
    my $className  = join( "::", @heritage );
    my $xClassName  = "x_" . join( "__", @heritage );

    # Check some method flags: constructor, destructor etc.
    my $flags = $m->{Flags};

    if ( !defined $flags ) {
	warn "Method ".$name.  " has no flags\n";
    }

    my $returnType = $m->{ReturnType};

    $returnType = undef if ($returnType eq 'void');

    # Don't use $className here, it's never the fully qualified (A::B) name for a ctor.
    my $isConstructor = ($name eq $classNode->{astNodeName} );
    my $isDestructor = ($returnType eq '~');

    if ($debug) {
        print STDERR " Method $name";
	print STDERR ", is DTOR" if $isDestructor;
	print STDERR ", returns $returnType" if $returnType;
	#print STDERR " ($m->{Access})";
	print STDERR "\n";
    }

    # Don't generate anything for destructors
    return if $isDestructor;

    return if ( $m->{SkipFromSwitch} ); # pure virtuals, etc.

#    # Skip internal methods, which return unknown types
#    # Hmm, the C# bindings have a list of those too.
#    return if ( $returnType =~ m/QGfx\s*\*/ );
#    return if ( $returnType eq 'CGContextRef' );
#    return if ( $returnType eq 'QWSDisplay *' );
#    # This stuff needs callback, or **
#    return if ( $name eq 'defineIOHandler' or $name eq 'qt_init_internal' );
#    # Skip casting operators, but not == < etc.
#    return if ( $name =~ /operator \w+/ );
#    # QFile's EncoderFn/DecoderFn
#    return if ( $name =~ /set[ED][ne]codingFunction/ );
#    # How to implement this? (QXmlDefaultHandler/QXmlEntityResolver::resolveEntity, needs A*&)
#    return if ( $name eq 'resolveEntity' and $className =~ /^QXml/ );
#    return if ( $className eq 'QBitArray' && $m->{Access} eq 'protected' );

    #print STDERR "Tests passed, generating.\n";

    # Detect objects returned by value
    checkIncludesForObject( $returnType, $addInclude ) if ($returnType);

    my $argId = 0;

    my @argTypeList=();

    foreach my $arg ( @{$m->{ParamList}} ) {

	print STDERR "  Param ".$arg->{astNodeName}." type: ".$arg->{ArgType}." name:".$arg->{ArgName}." default: ".$arg->{DefaultValue}."\n" if ($debug);

	my $argType = $arg->{ArgType};
	push @argTypeList, $argType;
		
	# Detect objects passed by value
	checkIncludesForObject( $argType, $addInclude );
	}    

    my @castedArgList = makeCastedArgList( @argTypeList );

    my $isStatic = $flags =~ "s";

    my $extra = "";
    $extra .= "static " if $isStatic || $isConstructor || $classNode->{NodeType} eq 'namespace';

    my $attr = "";
    $attr .= "const " if $flags =~ "c";

    my $this = $classNode->{BindingDerives} > 0 ? "this" : "xthis";

    # We iterate as many times as we have default params
    my $firstDefaultParam = $m->{FirstDefaultParam};
    $firstDefaultParam = scalar(@argTypeList) unless defined $firstDefaultParam;
    my $iterationCount = scalar(@argTypeList) - $firstDefaultParam;

    my $xretCode = '';
    if($returnType) {
	$xretCode .= coerce_type('x[0]', 'xret', $returnType, 1);
    }

    print STDERR "  ". ($iterationCount+1). " iterations for $name\n" if ($debug);

    while($iterationCount >= 0) {

	local($") = ",";
	# Handle case of a class with constructors, but with a private pure virtual
	# so we can't create an instance of it
	if($isConstructor and !$classNode->{CanBeInstanciated}) {

	    # We still generate "forwarder constructors" for x_className though
	    $methodCode .= "    $xClassName(";
	    my $i = 0;
	    for my $arg (@argTypeList) {
		$methodCode .= ", " if $i++;
		$methodCode .= "$arg x$i";
	    }
	    $methodCode .= ") : $className(";
	    $i = 0;
	    for my $arg (@argTypeList) {
		$methodCode .= ", " if $i++;
		$methodCode .= "x$i";
	    }
	    $methodCode .= ") {}\n";

	} else {

	    $switchCode .= "\tcase $methodNumber: ";
	    if ($flags =~ "s" || $isConstructor || $classNode->{NodeType} eq 'namespace') { # static, namespace or constructor
	        $switchCode .= "$xClassName\::";
	    } else {
	        $switchCode .= "xself->"
	    }
	    $switchCode .= "x_$methodNumber(args);";
	    $switchCode .= "\tbreak;\n";

	    $methodCode .= "    ${extra}void x_$methodNumber\(Smoke::Stack x) $attr\{\n";
	    my $cplusplusparams = join( ", ", @argTypeList );
	    $methodCode .= "\t// $name($cplusplusparams)\n";
	    $methodCode .= "\t";
	
	    if ($isConstructor) {

	        $methodCode .= "$xClassName* xret = new $xClassName(@castedArgList[0..$#argTypeList]);\n";
	        #$m->{retnew} = 1;
	        $methodCode .= "\tx[0].s_class = (void*)xret;\n"; # the return value, containing the new object
	        $methodCode .= "    }\n";

	        # Now generate the actual constructor for x_className
	        # (Simply a forwarder to the className constructor with the same args
			if ( $flags =~ "t" ) {
	        	$methodCode .= "    explicit $xClassName(";
			} else {
	        	$methodCode .= "    $xClassName(";
			}
	        my $i = 0;
	        for my $arg (@argTypeList) {
		    $methodCode .= ", " if $i++;
                    if ($arg =~ s/\(\*\)/(* x$i)/) { # function pointer... need to insert argname inside
                        $methodCode .= $arg;
                    } else {
		    $methodCode .= "$arg x$i";
                    }
	        }
	        $methodCode .= ") : $className(";
	        $i = 0;
	        for my $arg (@argTypeList) {
		    $methodCode .= ", " if $i++;
		    $methodCode .= "x$i";
	        }
	        $methodCode .= ") {\n";

	    } else {
	        $methodCode .= $returnType . " xret = " if $returnType;
	        $methodCode .= "$this\->" unless $isStatic || $classNode->{NodeType} eq 'namespace';
		if ($className ne $main::globalSpaceClassName) {
			if ($flags =~ "=") {
				# Setter method for a public instance variable
				my $varName = $name;
				$varName =~ /^set(\w)(.*)/;
				my $ch = $1;
				$ch =~ tr/A-Z/a-z/;
				$varName = $ch . $2;
				$methodCode .= "$varName = @castedArgList[0..$#argTypeList];\n";
			} else {
		    	$methodCode .= "$className\::$name(@castedArgList[0..$#argTypeList]);\n";
			}
		} elsif ($name =~ /^operator\s?\W+/) {
		    ( my $op = $name ) =~ s/^operator(.*)$/$1/;
		    if (scalar(@argTypeList) == 2) {
                        if( $name =~ /^operator(?:\+\+|--)/ ) { # postfix increment/decrement
                            $methodCode .= "(@castedArgList[0])$op;\n";
                        } else {
			    $methodCode .= "(@castedArgList[0] $op @castedArgList[1]);\n"; # a + b
                        }
		    } elsif (scalar(@argTypeList) == 1) {
			$methodCode .= "$op(@castedArgList[0]);\n"; # -a
		    } else {
			die "shouldn't reach here!";
		    }
		} else {
		    $methodCode .= "$name(@castedArgList[0..$#argTypeList]);\n";
		}
	        $methodCode .= "\t" . $xretCode if $returnType;
		# To avoid unused parameter warning, add this to void methods:
		$methodCode .= "\t(void)x; // noop (for compiler warning)\n" unless $returnType;
	    }
	    $methodCode .= "    }\n";
    }


	pop @argTypeList;
	$methodNumber++;
	$iterationCount--;
    } # Iteration loop

    return ( $methodCode, $switchCode );
}


sub generateEnum($$$)
{
    my( $classNode, $m, $addInclude ) = @_;	# input
    my $methodCode = '';	# output
    my $switchCode = '';	# output

    my @heritage = kdocAstUtil::heritage($classNode);
    my $className  = join( "::", @heritage );
    my $xClassName  = "x_" . join( "__", @heritage );
    
	my $fullEnumType = "$className\::". $m->{astNodeName};
	checkIncludesForObject( $fullEnumType, $addInclude );

    foreach my $enum ( @{$m->{ParamList}} ) {
	my $enumName = $enum->{ArgName};
	my $fullEnumName = "$className\::$enumName";
        die "Invalid index for $fullEnumName: $classNode->{case}{$fullEnumName} instead of $methodNumber" if $classNode->{case}{$fullEnumName} != $methodNumber;
	$methodCode .= "    static void x_$methodNumber(Smoke::Stack x) {\n";
	$methodCode .= "\tx[0].s_enum = (long)$fullEnumName;\n";
        $methodCode .= "    }\n";
        $switchCode .= "\tcase $methodNumber: $xClassName\::x_$methodNumber(args);\tbreak;\n";
        $methodNumber++;
    }

    return ( $methodCode, $switchCode );
}

sub generateVar($$$)
{
    my( $classNode, $m, $addInclude ) = @_;	# input
    my $methodCode = '';	# output
    my $switchCode = '';	# output

    my @heritage = kdocAstUtil::heritage($classNode);
    my $className  = join( "::", @heritage );
    my $xClassName  = "x_" . join( "__", @heritage );

    my $name = $m->{astNodeName};
    my $varType = $m->{Type};
    $varType =~ s/static\s//;
    $varType =~ s/const\s+(.*)\s*&/$1/;
    $varType =~ s/\s*$//;
    my $fullName = "$className\::$name";
    my $this = $classNode->{BindingDerives} > 0 ? "this" : "xthis";

    checkIncludesForObject( $varType, $addInclude );

    die "Invalid index for $fullName: $classNode->{case}{$fullName} instead of $methodNumber" if $classNode->{case}{$fullName} != $methodNumber;
	if ( $m->{Flags} =~ "s" ) {	
    	$methodCode .= "    static void x_$methodNumber(Smoke::Stack x) {\n        ";
    	$methodCode .= coerce_type('x[0]', $fullName, $varType, 1);
    	$methodCode .= "    }\n";
    	$switchCode .= "\tcase $methodNumber: $xClassName\::x_$methodNumber(args);\tbreak;\n";
	} else {
    	$methodCode .= "    void x_$methodNumber(Smoke::Stack x) {\n        ";
    	$methodCode .= coerce_type('x[0]', "$this->$name", $varType, 1);
    	$methodCode .= "    }\n";
    	$switchCode .= "\tcase $methodNumber: xself->x_$methodNumber(args);\tbreak;\n";
	}

    $methodNumber++;

    return ( $methodCode, $switchCode );
}

sub generateEnumCast($)
{
    my( $classNode ) = @_;
    my $methodCode = '';
    return unless keys %{$classNode->{enumerations}};
    $methodCode .= "    static void xenum_operation(Smoke::EnumOperation xop, Smoke::Index xtype, void *&xdata, long &xvalue) {\n";
    $methodCode .= "\tswitch(xtype) {\n";
    for my $enum (values %{$classNode->{enumerations}}) {
	
	# Hack - this shouldn't be needed here - deprecated enums
	next if ($enum eq 'KStatusBar::BarStatus' 
				or $enum eq 'KMdi::AddWindowFlags' 
				or $enum eq 'KToolBar::BarStatus' 
				or $enum eq 'KMimeType::Format:: compression : 4');
	
	my $type = findTypeEntry($enum);
	$methodCode .= "\t  case $type->{index}: //$enum\n";
	$methodCode .= "\t    switch(xop) {\n";
	$methodCode .= "\t      case Smoke::EnumNew:\n";
	$methodCode .= "\t\txdata = (void*)new $enum;\n";
	$methodCode .= "\t\tbreak;\n";
	$methodCode .= "\t      case Smoke::EnumDelete:\n";	# unnecessary
	$methodCode .= "\t\tdelete ($enum*)xdata;\n";
	$methodCode .= "\t\tbreak;\n";
	$methodCode .= "\t      case Smoke::EnumFromLong:\n";
	$methodCode .= "\t\t*($enum*)xdata = ($enum)xvalue;\n";
	$methodCode .= "\t\tbreak;\n";
	$methodCode .= "\t      case Smoke::EnumToLong:\n";
	$methodCode .= "\t\txvalue = (long)*($enum*)xdata;\n";
	$methodCode .= "\t\tbreak;\n";
	$methodCode .= "\t    }\n";
	$methodCode .= "\t    break;\n";
    }
    $methodCode .= "\t}\n";
    $methodCode .= "    }\n";

    return $methodCode;
} 

## Called by writeClassDoc
sub generateAllMethods
{
    my ($classNode) = @_;
    my $methodCode = '';
    my $switchCode = '';
    $methodNumber = 0;

    #my $className = $classNode->{astNodeName};
    my $className = join( "::", kdocAstUtil::heritage($classNode) );
    my $xClassName = "x_" . join( "__", kdocAstUtil::heritage($classNode) );
    my $isGlobalSpace = ($xClassName eq ("x_".$main::globalSpaceClassName));
    my $sourcename = $classNode->{Source}->{astNodeName};
   
    if ( $sourcename !~ s!.*($headerSubdirectories)(.*)!$1$2!m ) {
    	$sourcename =~ s!.*/(.*)!$1!m;
	}
    die "Empty source name for $classNode->{astNodeName}" if ( $sourcename eq '' );

    my %addInclude = ( $sourcename => 1 );

    if (!$isGlobalSpace) {
        if($classNode->{NodeType} eq 'namespace') {
           $switchCode .= "    (void)obj;\n";
            $methodCode .= "public:\n";
        	my $s;
        	for my $sn( @{$classNode->{Sources}} ) {
    		if ( ($s = $sn->{astNodeName}) !~ s!.*($headerSubdirectories)(.*)!$1$2!m ) {
    			$s =~ s!.*/(.*)!$1!m;
			}
			$addInclude{ $s } = 1;
        	}
         } elsif(! $classNode->{BindingDerives}) {
            $methodCode .= "private:\n";
            $methodCode .= "    $className *xthis;\n";
            $methodCode .= "public:\n";
            $methodCode .= "    $xClassName\(void *x) : xthis(($className*)x) {}\n";
            $switchCode .= "    $xClassName xtmp(obj), *xself = &xtmp;\n";
        } else {
            $switchCode .= "    $xClassName *xself = ($xClassName*)obj;\n";
            $methodCode .= "public:\n";
        }
    } else {
        my $s;
        for my $sn( @{$classNode->{Sources}} ) {
    	if ( ($s = $sn->{astNodeName}) !~ s!.*($headerSubdirectories)(.*)!$1$2!m ) {
    		$s =~ s!.*/(.*)!$1!m;
		}
		$addInclude{ $s } = 1;
        }
	$methodCode .= "public:\n";
	$switchCode .= "    (void) obj;\n";
    }
    $switchCode .= "    switch(xi) {\n";

    # Do all enums first
    Iter::MembersByType ( $classNode, undef,
			  sub {	my ($classNode, $methodNode ) = @_;
				
	if ( $methodNode->{NodeType} eq 'enum' ) {
	    my ($meth, $swit) = generateEnum( $classNode, $methodNode, \%addInclude );
	    $methodCode .= $meth;
	    $switchCode .= $swit;
	}
				}, undef );

    # Then all static vars
    Iter::MembersByType ( $classNode, undef,
			  sub {	my ($classNode, $methodNode ) = @_;
				
	if ( $methodNode->{NodeType} eq 'var' ) {
	    my ($meth, $swit) = generateVar( $classNode, $methodNode, \%addInclude );
	    $methodCode .= $meth;
	    $switchCode .= $swit;
	}
				}, undef );

    # Then all methods
    Iter::MembersByType ( $classNode, undef,
			  sub {	my ($classNode, $methodNode ) = @_;

        if ( $methodNode->{NodeType} eq 'method' ) {
	    my ($meth, $swit) = generateMethod( $classNode, $methodNode, \%addInclude );
	    $methodCode .= $meth;
	    $switchCode .= $swit;
	}
			      }, undef );

    # Virtual methods
    if ($classNode->{BindingDerives}) {
	my %virtualMethods;
	allVirtualMethods( $classNode, \%virtualMethods );

	for my $sig (sort keys %virtualMethods) {
            my ($meth) = generateVirtualMethod( $classNode, $sig, $virtualMethods{$sig}{method}, $virtualMethods{$sig}{class}, \%addInclude );
	    $methodCode .= $meth;
	}
    }

    $methodCode .= generateEnumCast( $classNode );

    # Destructor
    # "virtual" is useless, if the base class has a virtual destructor then the x_* class too.
    #if($classNode->{HasVirtualDestructor} and $classNode->{HasDestructor}) {
    #	$methodCode .= "    virtual ~$xClassName() {}\n";
    #}
    # We generate a dtor though, because we might want to add stuff into it
    if ( !$isGlobalSpace && $classNode->{NodeType} ne 'namespace' ) {
        $methodCode .= "    ~$xClassName() { ${libname}_Smoke->binding->deleted($classNode->{ClassIndex}, (void*)this); }\n";
    }

    if ($classNode->{CanBeInstanciated} and $classNode->{HasPublicDestructor}) {
	die "$className destructor: methodNumber=$methodNumber != case entry=".$classNode->{case}{"~$className()"}."\n"
	     if $methodNumber != $classNode->{case}{"~$className()"};
	$switchCode .= "\tcase $methodNumber: delete ($className*)xself;\tbreak;\n";
	$methodNumber++;
    }

    $switchCode .= "    }\n";
    return ( $methodCode, $switchCode, \%addInclude );
}

# Return 0 if the class has no virtual dtor, 1 if it has, 2 if it's private
sub hasVirtualDestructor($)
{
    my ( $classNode ) = @_;
    my $className = join( "::", kdocAstUtil::heritage($classNode) );
    return if ( $skippedClasses{$className} );

    my $parentHasIt;
    # Look at ancestors, and (recursively) call hasVirtualDestructor for each
    # It's enough to have one parent with a prot/public virtual dtor
    Iter::Ancestors( $classNode, $rootnode, undef, undef, sub {
                     my $vd = hasVirtualDestructor( $_[0] );
                     $parentHasIt = $vd unless $parentHasIt > $vd;
                    } );
    return $parentHasIt if $parentHasIt; # 1 or 2

    # Now look in $classNode - including private methods
    my $doPrivate = $main::doPrivate;
    $main::doPrivate = 1;
    my $result;
    Iter::MembersByType ( $classNode, undef,
		sub {	my ($classNode, $m ) = @_;
			return unless( $m->{NodeType} eq "method" && $m->{ReturnType} eq '~' );

			if ( $m->{Flags} =~ /[vp]/ ) {
			    if ( $m->{Access} =~ /private/ ) {
				$result=2; # private virtual
			    } else {
				$result=1; # [protected or public] virtual
			    }
			}
		},
		undef
	);
    $main::doPrivate = $doPrivate;
    $result=0 if (!defined $result);
    return $result;
}

=head2 allVirtualMethods

	Parameters: class node, dict

	Adds to the dict, for all method nodes that are virtual, in this class and in parent classes :
        {method} the method node, {class} the class node (the one where the virtual is implemented)

=cut

sub allVirtualMethods($$)
{
    my ( $classNode, $virtualMethods ) = @_;
    my $className = join( "::", kdocAstUtil::heritage($classNode) );
    return if ( $skippedClasses{$className} );

    # Look at ancestors, and (recursively) call allVirtualMethods for each
    # This is done first, so that virtual methods that are reimplemented as 'private'
    # can be removed from the list afterwards (below)
    Iter::Ancestors( $classNode, $rootnode, undef, undef, sub {
			 allVirtualMethods( @_[0], $virtualMethods );
		     }, undef
		   );

    # Now look for virtual methods in $classNode - including private ones
    my $doPrivate = $main::doPrivate;
    $main::doPrivate = 1;
    Iter::MembersByType ( $classNode, undef,
		sub {	my ($classNode, $m ) = @_;
			# Only interested in methods, and skip destructors
			return unless( $m->{NodeType} eq "method" && $m->{ReturnType} ne '~' );

			my $signature = methodSignature( $m, $#{$m->{ParamList}} );
			print STDERR $signature . " ($m->{Access})\n" if ($debug);

			# A method is virtual if marked as such (v=virtual p=pure virtual)
			# or if a parent method with same signature was virtual
			if ( $m->{Flags} =~ /[vp]/ or defined $virtualMethods->{$signature} ) {
			    if ( $m->{Access} =~ /private/ ) {
				if ( defined $virtualMethods->{$signature} ) { # remove previously defined
				    delete $virtualMethods->{$signature};
				}
				# else, nothing, just ignore private virtual method
			    } else {
				$virtualMethods->{$signature}{method} = $m;
				$virtualMethods->{$signature}{class} = $classNode;
			    }
			}
		},
		undef
	);
    $main::doPrivate = $doPrivate;
}

# Known typedef? If so, apply it.
sub applyTypeDef($)
{
    my $type = shift;
    # Parse 'const' in front of it, and '*' or '&' after it
    my $prefix = $type =~ s/^const\s+// ? 'const ' : '';
    my $suffix = $type =~ s/\s*([\&\*]+)$// ? $1 : '';

    if (exists $typedeflist{$type}) {
	return $prefix.$typedeflist{$type}.$suffix;
    }
    return $prefix.$type.$suffix;
}

# Register type ($1) into %allTypes if not already there
sub registerType($$) {
    my $type = shift;
    #print "registerType: $type\n" if ($debug);

    $type =~ s/\s+const$//; # for 'char* const'
    $type =~ s/\s+const\s*\*$/\*/; # for 'char* const*'
	
	$type =~ s/(<[^>]*)\s+([^>]*>)/$1$2/; # Remove embedded space from template types, such as
										  # 'QMap<QCString, DCOPRef>'

    return if ( $type eq 'void' or $type eq '' or $type eq '~' );
    die if ( $type eq '...' );     # ouch

    # Let's register the real type, not its known equivalent
    #$type = applyTypeDef($type);

    # Enum _value_ -> get corresponding type
    if (exists $enumValueToType{$type}) {
	$type = $enumValueToType{$type};
    }

    # Already in allTypes
    if(exists $allTypes{$type}) {
        return;
    }

    die if $type eq 'QTextEdit::UndoRedoInfo::Type';
    die if $type eq '';

    my $realType = $type;

    # Look for references (&) and pointers (* or **)  - this will not handle *& correctly.
    # We do this parsing here because both the type list and iterproto need it
    if($realType =~ s/&$//) {
	$allTypes{$type}{typeFlags} = 'Smoke::tf_ref';
    }
    elsif($realType ne 'void*' && $realType =~ s/\*$//) {
	$allTypes{$type}{typeFlags} = 'Smoke::tf_ptr';
    }
    else {
	$allTypes{$type}{typeFlags} = 'Smoke::tf_stack';
    }

    if ( $realType =~ s/^const\s+// ) { # Remove 'const'
	$allTypes{$type}{typeFlags} .= ' | Smoke::tf_const';
    }

    # Apply typedefs, and store the resulting type.
    # For instance, if $type was Q_UINT16&, realType will be ushort
    $allTypes{$type}{realType} = applyTypeDef( $realType );

    # In the first phase we only create entries into allTypes.
    # The values (indexes) are calculated afterwards, once the list is full.
    $allTypes{$type}{index} = -1;
    #print STDERR "Register $type. Realtype: $realType\n" if($debug);
}

# Get type from %allTypes
# This returns a hash with {index}, {isEnum}, {typeFlags}, {realType}
# (and {typeId} after the types array is written by writeSmokeDataFile)
sub findTypeEntry($) {
    my $type = shift;
    my $typeIndex = -1;
    $type =~ s/\s+const$//; # for 'char* const'
    $type =~ s/\s+const\s*\*$/\*/; # for 'char* const*'

	$type =~ s/(<[^>]*)\s+([^>]*>)/$1$2/; # Remove embedded space from template types, such as
										  # 'QMap<QCString, DCOPRef>'

    return undef if ( $type =~ '~' or $type eq 'void' or $type eq '' );

    # Enum _value_ -> get corresponding type
    if (exists $enumValueToType{$type}) {
	$type = $enumValueToType{$type};
    }

    die "type not known: $type" unless defined $allTypes{$type};
    return $allTypes{ $type };
}

# List of all super-classes for a given class
sub superclass_list($)
{
    my $classNode = shift;
    my @super;
    Iter::Ancestors( $classNode, $rootnode, undef, undef, sub {
			push @super, @_[0];
			push @super, superclass_list( @_[0] );
		     }, undef );
    return @super;
}

# Store the {case} dict in the class Node (method signature -> index in the "case" switch)
# This also determines which methods should NOT be in the switch, and sets {SkipFromSwitch} for them
sub prepareCaseDict($) {

     my $classNode = shift;
     my $className = join( "::", kdocAstUtil::heritage($classNode) );
     $classNode->AddProp("case", {});
     my $methodNumber = 0;

     # First look at all enums for this class
     Iter::MembersByType ( $classNode, undef,
		sub {	my ($classNode, $m ) = @_;

	next unless $m->{NodeType} eq 'enum';
	foreach my $val ( @{$m->{ParamList}} ) {
	    my $fullEnumName = "$className\::".$val->{ArgName};
	    print STDERR "Enum: $fullEnumName -> case $methodNumber\n" if ($debug);
	    $classNode->{case}{$fullEnumName} = $methodNumber;
	    $enumValueToType{$fullEnumName} = "$className\::$m->{astNodeName}";
	    $methodNumber++;
	}
		      }, undef );

     # Check for vars
     Iter::MembersByType ( $classNode, undef,
		sub {	my ($classNode, $m ) = @_;

	    next unless $m->{NodeType} eq 'var';
	    my $name = "$className\::".$m->{astNodeName};			
	    print STDERR "Var: $name -> case $methodNumber\n" if ($debug);
	    $classNode->{case}{$name} = $methodNumber;
	    $methodNumber++;

		      }, undef );

	 my %const_methods = ();
     # Now look at all const methods for this class, in order to use
	 # them in preference to any otherwise identical non-const method
     Iter::MembersByType ( $classNode, undef,
		sub {	my ($classNode, $m ) = @_;
	
		next unless $m->{NodeType} eq 'method';
		my @args = @{ $m->{ParamList} };
	    my $sig = methodSignature( $m, $#args );
		if ( $sig =~ /(.*) const$/ ) {
			$const_methods{$1} = 1;
		}
		
		      }, undef );

     # Now look at all methods for this class
     Iter::MembersByType ( $classNode, undef,
		sub {	my ($classNode, $m ) = @_;

	next unless $m->{NodeType} eq 'method';
	my $name = $m->{astNodeName};
        my $isConstructor = ($name eq $classNode->{astNodeName} );
	if ($isConstructor and ($m->{ReturnType} eq '~')) # destructor
	{
	    # Remember whether we'll generate a switch entry for the destructor
	    $m->{SkipFromSwitch} = 1 unless ($classNode->{CanBeInstanciated} and $classNode->{HasPublicDestructor});
	    next;
	}

        # Don't generate bindings for protected methods (incl. signals) if
        # we're not deriving from the C++ class. Only take public and public_slots
        my $ok = ( $classNode->{BindingDerives} or $m->{Access} =~ /public/ ) ? 1 : 0;

        # Don't generate bindings for pure virtuals - we can't call them ;)
        $ok = 0 if ( $ok && $m->{Flags} =~ "p" );

        # Bugfix for Qt-3.0.4: those methods are NOT implemented (report sent).
        $ok = 0 if ( $ok && $className eq 'QLineEdit' && ( $name eq 'setPasswordChar' || $name eq 'passwordChar' ) );
        $ok = 0 if ( $ok && $className eq 'QWidgetItem' && $name eq 'widgetSizeHint' );

        if ( !$ok )
        {
	    #print STDERR "Skipping $className\::$name\n" if ($debug);
	    $m->{SkipFromSwitch} = 1;
	    next;
	}

	my @args = @{ $m->{ParamList} };
	my $sig = methodSignature( $m, $#args );
	if ( $const_methods{$sig} && $m->{Flags} !~ "v" ) {
		# If there is a method which just differs from another by 'constness',
		# then ignore the non-const version
	    $m->{SkipFromSwitch} = 1;
	    next;
	}
	my $last = $m->{FirstDefaultParam};
	$last = scalar @args unless defined $last;
	my $iterationCount = scalar(@args) - $last;
	while($iterationCount >= 0) {
	    $sig = methodSignature( $m, $#args );
	    $classNode->{case}{$sig} = $methodNumber;
	    #print STDERR "prepareCaseDict: registered case number $methodNumber for $sig in $className()\n" if ($debug);
	    pop @args;
	    $iterationCount--;
	    $methodNumber++;
	}
		    }, undef );

    # Add the destructor, at the end
    if ($classNode->{CanBeInstanciated} and $classNode->{HasPublicDestructor}) {
        $classNode->{case}{"~$className()"} = $methodNumber;
	# workaround for ~Sub::Class() being seen as Sub::~Class()
	$classNode->{case}{"~$classNode->{astNodeName}()"} = $methodNumber;
	#print STDERR "prepareCaseDict: registered case number $methodNumber for ~$className()\n" if ($debug);
    }
}

=head2
	Write out the smokedata.cpp file containing all the arrays.
=cut

sub writeSmokeDataFile($) {
    my $rootnode = shift;

    # Make list of classes
    my %allIncludes; # list of all header files for all classes
    my @classlist;
    push @classlist, ""; # Prepend empty item for "no class"
    my %enumclasslist;
    Iter::LocalCompounds( $rootnode, sub {
	my $classNode = $_[0];
	my $className = join( "::", kdocAstUtil::heritage($classNode) );
	
	push @classlist, $className;
	$enumclasslist{$className}++ if keys %{$classNode->{enumerations}};
	$classNode->{ClassIndex} = $#classlist;
	addIncludeForClass( $classNode, \%allIncludes, undef );
    } );

    my %classidx = do { my $i = 0; map { $_ => $i++ } @classlist };

    my $file = "$outputdir/smokedata.cpp";
    open OUT, ">$file" or die "Couldn't create $file\n";

    foreach my $incl (sort{ 
                           return 1 if $a=~/qmotif/;  # move qmotif* at bottom (they include dirty X11 headers)
                           return -1 if $b=~/qmotif/;
			   return -1 if substr($a,0,1) eq 'q' and substr($b,0,1) ne 'q'; # move Qt headers on top
			   return 1 if substr($a,0,1) ne 'q' and substr($b,0,1) eq 'q';			   
                           $a cmp $b
                          } keys %allIncludes) {
	die if $incl eq '';
        if( $incl eq "kxmlguifactory.h" ) {
            print OUT "#include <kxmlguiclient.h>\n";
        }
	print OUT "#include <$incl>\n";
    }	

    print OUT "\n";
    print OUT "#include <smoke.h>\n\n";
    print OUT "#include <qt_smoke.h>\n\n";

    # gcc optimizes this method like crazy. switch() is godly
    print OUT "static void *${libname}_cast(void *xptr, Smoke::Index from, Smoke::Index to) {\n";
    print OUT "    switch(from) {\n";

    print STDERR "Writing ${libname}_cast function\n" if ($debug);

    # Prepare descendants information for each class
    my %descendants; # classname -> list of descendant nodes
    Iter::LocalCompounds( $rootnode, sub {
	my $classNode = shift;
	# Get _all_ superclasses (up any number of levels)
	# and store that $classNode is a descendant of $s
	my @super = superclass_list($classNode);
	for my $s (@super) {
	    my $superClassName = join( "::", kdocAstUtil::heritage($s) );
	    Ast::AddPropList( \%descendants, $superClassName, $classNode );
	}
    } );

    # Iterate over all classes, to write the xtypecast function
    Iter::LocalCompounds( $rootnode, sub {
	my $classNode = shift;
	my $className = join( "::", kdocAstUtil::heritage($classNode) );
	# @super will contain superclasses, the class itself, and all descendants
	my @super = superclass_list($classNode);
	push @super, $classNode;
        if ( defined $descendants{$className} ) {
	    push @super, @{$descendants{$className}};
	}
	my $cur = $classidx{$className};
	
	return if $classNode->{NodeType} eq 'namespace';

	print OUT "      case $cur:\t//$className\n";
	print OUT "\tswitch(to) {\n";
	$cur = -1;
	my %casevalues;
	for my $s (@super) {
		my $superClassName = join( "::", kdocAstUtil::heritage($s) );
		next if !defined $classidx{$superClassName}; # inherits from unknown class, see below
		next if $classidx{$superClassName} == $cur;    # shouldn't happen in Qt
		if (!defined $s) {
			die "problem with $className missing parent"
		}
		next if $s->kdocAstUtil::inheritsAsVirtual($classNode); # can't cast from a virtual base class
		$cur = $classidx{$superClassName}; # KDE has MI with diamond shaped cycles (cf. KXMLGUIClient)
		next if $casevalues{$cur};         # ..so skip any duplicate parents
		print OUT "\t  case $cur: return (void*)($superClassName*)($className*)xptr;\n";
		$casevalues{$cur} = 1;
	}
	print OUT "\t  default: return xptr;\n";
	print OUT "\t}\n";
    } );
    print OUT "      default: return xptr;\n";
    print OUT "    }\n";
    print OUT "}\n\n";


    # Write inheritance array
    # Imagine you have "Class : public super1, super2"
    # The inheritlist array will get 3 new items: super1, super2, 0
    my %inheritfinder;  # key = (super1, super2) -> data = (index in @inheritlist). This one allows reuse.
    my %classinherit;   # we store that index in %classinherit{className}
    # We don't actually need to store inheritlist in memory, we write it
    # directly to the file. We only need to remember its current size.
    my $inheritlistsize = 1;

    print OUT "// Group of class IDs (0 separated) used as super class lists.\n";
    print OUT "// Classes with super classes have an index into this array.\n";
    print OUT "static short ${libname}_inheritanceList[] = {\n";
    print OUT "\t0,\t// 0: (no super class)\n";
    Iter::LocalCompounds( $rootnode, sub {
	my $classNode = shift;
	my $className = join( "::", kdocAstUtil::heritage($classNode) );
	
	print STDERR "inheritanceList: looking at $className\n" if ($debug);

	# Make list of direct ancestors
	my @super;
	Iter::Ancestors( $classNode, $rootnode, undef, undef, sub {
			     my $superClassName = join( "::", kdocAstUtil::heritage($_[0]) );
			     push @super, $superClassName;
		    }, undef );
	# Turn that into a list of class indexes
	my $key = '';
	foreach my $superClass( @super ) {
	    if (defined $classidx{$superClass}) {
		$key .= ', ' if ( length $key > 0 );
		$key .= $classidx{$superClass};
	    }
	}
	if ( $key ne '' ) {
	    if ( !defined $inheritfinder{$key} ) {
		print OUT "\t";
		my $index = $inheritlistsize; # Index of first entry (for this group) in inheritlist
		foreach my $superClass( @super ) {
		    if (defined $classidx{$superClass}) {
			print OUT "$classidx{$superClass}, ";
			$inheritlistsize++;
		    }
		}
		$inheritlistsize++;
		my $comment = join( ", ", @super );
		print OUT "0,\t// $index: $comment\n";
		$inheritfinder{$key} = $index;
	    }
	    $classinherit{$className} = $inheritfinder{$key};
	} else { # No superclass
	    $classinherit{$className} = 0;
	}
    } );
    print OUT "};\n\n";


    print OUT "// These are the xenum functions for manipulating enum pointers\n";
    for my $className (keys %enumclasslist) {
	my $c = $className;
	$c =~ s/::/__/g;
	print OUT "void xenum_$c\(Smoke::EnumOperation, Smoke::Index, void*&, long&);\n";
    }
    print OUT "\n";
    print OUT "// Those are the xcall functions defined in each x_*.cpp file, for dispatching method calls\n";
    my $firstClass = 1;
    for my $className (@classlist) {
	if ($firstClass) {
	    $firstClass = 0;
	    next;
	}
	my $c = $className;   # make a copy
	$c =~ s/::/__/g;
	print OUT "void xcall_$c\(Smoke::Index, void*, Smoke::Stack);\n";
    }
    print OUT "\n";

    # Write class list afterwards because it needs offsets to the inheritance array.
    print OUT "// List of all classes\n";
    print OUT "// Name, index into inheritanceList, method dispatcher, enum dispatcher, class flags\n";
    print OUT "static Smoke::Class ${libname}_classes[] = {\n";
    my $firstClass = 1;
    Iter::LocalCompounds( $rootnode, sub {
	my $classNode = shift;
	my $className = join( "::", kdocAstUtil::heritage($classNode) );

	if ($firstClass) {
	    $firstClass = 0;
	    print OUT "\t{ 0L, 0, 0, 0, 0 }, \t// 0 (no class)\n";
	}
	my $c = $className;
	$c =~ s/::/__/g;
	my $xcallFunc = "xcall_$c";
	my $xenumFunc = "0";
	$xenumFunc = "xenum_$c" if exists $enumclasslist{$className};
	die "problem with $className" unless defined $classinherit{$className};

	my $xClassFlags = 0;
	$xClassFlags .= "|Smoke::cf_constructor" if $classNode->{CanBeInstanciated}; # correct?
	$xClassFlags .= "|Smoke::cf_deepcopy" if $classNode->{CanBeCopied}; # HasCopyConstructor would be wrong (when it's private)
	$xClassFlags .= "|Smoke::cf_virtual" if hasVirtualDestructor($classNode) == 1;
	# $xClassFlags .= "|Smoke::cf_undefined" if ...;
	$xClassFlags =~ s/0\|//; # beautify
	print OUT "\t{ \"$className\", $classinherit{$className}, $xcallFunc, $xenumFunc, $xClassFlags }, \t//$classidx{$className}\n";
    } );
    print OUT "};\n\n";


    print OUT "// List of all types needed by the methods (arguments and return values)\n";
    print OUT "// Name, class ID if arg is a class, and TypeId\n";
    print OUT "static Smoke::Type ${libname}_types[] = {\n";
    my $typeCount = 0;
    $allTypes{''}{index} = 0; # We need an "item 0"
    for my $type (sort keys %allTypes) {
	$allTypes{$type}{index} = $typeCount;      # Register proper index in allTypes
	if ( $typeCount == 0 ) {
	    print OUT "\t{ 0, 0, 0 },\t//0 (no type)\n";
	    $typeCount++;
	    next;
	}
	my $isEnum = $allTypes{$type}{isEnum};
	my $typeId;
	my $typeFlags = $allTypes{$type}{typeFlags};
	my $realType = $allTypes{$type}{realType};
	die "$type" if !defined $typeFlags;
#	die "$realType" if $realType =~ /\(/;
	if ($realType =~ /\(/) {
		print "FATAL ERROR $type $realType\n";
	}
	# First write the name
	print OUT "\t{ \"$type\", ";
	# Then write the classId (and find out the typeid at the same time)
	if(exists $classidx{$realType}) { # this one first, we want t_class for QBlah*
	    $typeId = 't_class';
	    print OUT "$classidx{$realType}, ";
	}
	elsif($type =~ /&$/ || $type =~ /\*$/) {
	    $typeId = 't_voidp';
	    print OUT "0, "; # no classId
	}
	elsif($isEnum || $allTypes{$realType}{isEnum}) {
	    $typeId = 't_enum';
	    if($realType =~ /(.*)::/) {
		my $c = $1;
		if($classidx{$c}) {
		    print OUT "$classidx{$c}, ";
		} else {
		    print OUT "0 /* unknown class $c */, ";
		}
	    } else {
		print OUT "0 /* unknown $realType */, "; # no classId
	    }
	}
	else {
	    $typeId = $typeunion{$realType};
	    if (defined $typeId) {
		$typeId =~ s/s_/t_/; # from s_short to t_short for instance
	    }
	    else {
		# Not a known class - ouch, this happens quite a lot
		# (private classes, typedefs, template-based types, etc)
		if ( $skippedClasses{$realType} ) {
#		    print STDERR "$realType has been skipped, using t_voidp for it\n";
		} else {
		    unless( $realType =~ /</ ) { # Don't warn for template stuff...
			print STDERR "$realType isn't a known type (type=$type)\n";
		    }
		}
		$typeId = 't_voidp'; # Unknown -> map to a void *
	    }
	    print OUT "0, "; # no classId
	}
	# Then write the flags
	die "$type" if !defined $typeId;
	print OUT "Smoke::$typeId | $typeFlags },";
	print OUT "\t//$typeCount\n";
	$typeCount++;
	# Remember it for coerce_type
	$allTypes{$type}{typeId} = $typeId;
    }
    print OUT "};\n\n";


    my %arglist; # registers the needs for argumentList (groups of type ids)
    my %methods;
    # Look for all methods and all enums, in all classes
    # And fill in methods and arglist. This loop writes nothing to OUT.
    Iter::LocalCompounds( $rootnode, sub {
	my $classNode = shift;
	my $className = join( "::", kdocAstUtil::heritage($classNode) );
	print STDERR "writeSmokeDataFile: arglist: looking at $className\n" if ($debug);

	Iter::MembersByType ( $classNode, undef,
		sub {	my ($classNode, $m ) = @_;

	my $methName = $m->{astNodeName};
	# For destructors, get a proper signature that includes the '~'
	if ( $m->{ReturnType} eq '~' )
	{
	    $methName = '~' . $methName ;
	    # Let's even store that change, otherwise we have to do it many times
	    $m->{astNodeName} = $methName;
	}
	
	if( $m->{NodeType} eq "enum" ) {

	    foreach my $enum ( @{$m->{ParamList}} ) {
		my $enumName = $enum->{ArgName};
	        $methods{$enumName}++;
	    }

	} elsif ( $m->{NodeType} eq 'var' ) {
		$methods{$m->{astNodeName}}++;
	} elsif( $m->{NodeType} eq "method" ) {

	    $methods{$methName}++;
	    my @protos;
	    makeprotos(\%classidx, $m, \@protos);

	    #print "made @protos from $className $methName $m->{Signature})\n" if ($debug);
	    for my $p (@protos) {
		$methods{$p}++;
		my $argcnt = 0;
		$argcnt = length($1) if $p =~ /([\$\#\?]+)/;
		my $sig = methodSignature($m, $argcnt-1);
		# Store in a class hash named "proto", a proto+signature => method association
		$classNode->{proto}{$p}{$sig} = $m;
		#$classNode->{signature}{$sig} = $p;
		# There's probably a way to do this better, but this is the fastest way
		# to get the old code going: store classname into method
		$m->{class} = $className;
	    }

	    my $firstDefaultParam = $m->{FirstDefaultParam};
	    $firstDefaultParam = scalar(@{ $m->{ParamList} }) unless defined $firstDefaultParam;
	    my $argNames = '';
	    my $args = '';
	    for(my $i = 0; $i < @{ $m->{ParamList} }; $i++) {
		$args .= ', ' if $i;
		$argNames .= ', ' if $i;
		my $argType = $m->{ParamList}[$i]{ArgType};
		my $typeEntry = findTypeEntry( $argType );
		$args .= defined $typeEntry ? $typeEntry->{index} : 0;
		$argNames .= $argType;

		if($i >= ($firstDefaultParam - 1)) {
		    #print "arglist entry: $args\n";
		    $arglist{$args} = $argNames;
		}
		
	    }
	    # create an entry for e.g. "arg0,arg1,arg2" where argN is index in allTypes of type for argN
	    # The value, $argNames, is temporarily stored, to be written out as comment
	    # It gets replaced with the index in the next loop.
	    #print "arglist entry : $args\n";
	    $arglist{$args} = $argNames;
	}
		    }, # end of sub
	undef
       );
    });


    $arglist{''} = 0;
    # Print arguments array
    print OUT "static Smoke::Index ${libname}_argumentList[] = {\n";
    my $argListCount = 0;
    for my $args (sort keys %arglist) {
	my $numTypes = scalar(split ',', $args);
	if ($args eq '') {
	    print OUT "\t0,\t//0  (void)\n";
	} else {
	    # This is a nice trick : args can be written in one go ;)
	    print OUT "\t$args, 0,\t//$argListCount  $arglist{$args}  \n";
	}
	$arglist{$args} = $argListCount;      # Register proper index in argList
	$argListCount += $numTypes + 1;       # Move forward by as much as we wrote out
    }
    print OUT "};\n\n";

    $methods{''} = 0;
    my @methodlist = sort keys %methods;
    my %methodidx = do { my $i = 0; map { $_ => $i++ } @methodlist };

    print OUT "// Raw list of all methods, using munged names\n";
    print OUT "static const char *${libname}_methodNames[] = {\n";
    my $methodNameCount = $#methodlist;
    for my $m (@methodlist) {
	print OUT qq(    "$m",\t//$methodidx{$m}\n);
    }
    print OUT "};\n\n";

    print OUT "// (classId, name (index in methodNames), argumentList index, number of args, method flags, return type (index in types), xcall() index)\n";
    print OUT "static Smoke::Method ${libname}_methods[] = {\n";
    my @methods;
    %allMethods = ();
    my $methodCount = 0;
    # Look at all classes and all enums again
    Iter::LocalCompounds( $rootnode, sub {
	my $classNode = shift;
	my $className = join( "::", kdocAstUtil::heritage($classNode) );
	
	my $classIndex = $classidx{$className};
	print STDERR "writeSmokeDataFile: methods: looking at $className\n" if ($debug);

	Iter::MembersByType ( $classNode, undef,
		sub {	my ($classNode, $m ) = @_;

	if( $m->{NodeType} eq "enum" ) {

	    foreach my $enum ( @{$m->{ParamList}} ) {
		my $enumName = $enum->{ArgName};
		my $fullEnumName = "$className\::$enumName";
		my $sig = "$className\::$enumName\()";
		my $xmethIndex = $methodidx{$enumName};
		die "'Method index' for enum $sig not found" unless defined $xmethIndex;
		my $typeId = findTypeEntry( $fullEnumName )->{index};
		die "enum has no {case} value in $className: $fullEnumName" unless defined $classNode->{case}{$fullEnumName};
		print OUT "\t{$classIndex, $xmethIndex, 0, 0, Smoke::mf_static|Smoke::mf_enum, $typeId, $classNode->{case}{$fullEnumName}},\t//$methodCount $fullEnumName (enum)\n";
		$allMethods{$sig} = $methodCount;
		print STDERR "Added entry for " . $sig . " into \$allMethods\n" if ($debug);
		$methods[$methodCount] = {
				c => $classIndex,
				methIndex => $xmethIndex,
				argcnt => '0',
				args => 0,
				retTypeIndex => 0,
				idx => $classNode->{case}{$fullEnumName}
			       };
		$methodCount++;
	    }

	} elsif( $m->{NodeType} eq 'var' ) {

	    my $name = $m->{astNodeName};
	    my $fullName = "$className\::$name";
	    my $sig = "$fullName\()";
	    my $xmethIndex = $methodidx{$name};
	    die "'Method index' for var $sig not found" unless defined $xmethIndex;
	    my $varType = $m->{Type};
	    $varType =~ s/static\s//;
	    $varType =~ s/const\s+(.*)\s*&/$1/;
	    $varType =~ s/\s*$//;
	    my $typeId = findTypeEntry( $varType )->{index};
	    die "var has no {case} value in $className: $fullName" unless defined $classNode->{case}{$fullName};
		if ( $m->{Flags} =~ "s" ) {
	    	print OUT "\t{$classIndex, $xmethIndex, 0, 0, Smoke::mf_static, $typeId, $classNode->{case}{$fullName}},\t//$methodCount $fullName (static var)\n";
		} else {
	    	print OUT "\t{$classIndex, $xmethIndex, 0, 0, 0, $typeId, $classNode->{case}{$fullName}},\t//$methodCount $fullName (var)\n";
		}
        $allMethods{$sig} = $methodCount;
	    print STDERR "Added entry for " . $sig . " into \$allMethods\n" if ($debug);
	    $methods[$methodCount] = {
				c => $classIndex,
				methIndex => $xmethIndex,
				argcnt => '0',
				args => 0,
				retTypeIndex => 0,
				idx => $classNode->{case}{$fullName}
			       };
	    $methodCount++;


	} elsif( $m->{NodeType} eq "method" ) {

	    # We generate a method entry only if the method is in the switch() code
	    # BUT: for pure virtuals, they need to have a method entry, even though they
	    # do NOT have a switch code.
	    return if ( $m->{SkipFromSwitch} && $m->{Flags} !~ "p" );

	    # No switch code for destructors if we didn't derive from the class (e.g. it has private ctors only)
    	    return if ( $m->{ReturnType} eq '~' && ! ( $classNode->{BindingDerives} and $classNode->{HasPublicDestructor}) );

            # Is this sorting really important?
	    #for my $m (sort {$a->{name} cmp $b->{name}} @{ $self->{$c}{method} }) {

	    my $methName = $m->{astNodeName};
	    my $def = $m->{FirstDefaultParam};
	    $def = scalar(@{ $m->{ParamList} }) unless defined $def;
	    my $last = scalar(@{ $m->{ParamList} }) - 1;
	    #print STDERR "writeSmokeDataFile: methods: generating for method $methName, def=$def last=$last\n" if ($debug);

	    while($last >= ($def-1)) {
		last if $last < -1;
		my $args = [ @{ $m->{ParamList} }[0..$last] ];
		my $sig = methodSignature($m, $last);
		#my $methodSig = $classNode->{signature}{$sig}; # Munged signature
		#print STDERR "writeSmokeDataFile: methods: sig=$className\::$sig methodSig=$methodSig\n" if ($debug);
		#my $methodIndex = $methodidx{$methodSig};
		#die "$methodSig" if !defined $methodIndex;

		my $methodIndex = $methodidx{$methName};
		die "$methName" if !defined $methodIndex;
		my $case = $classNode->{case}{$sig};
		my $typeEntry = findTypeEntry( $m->{ReturnType} );
		my $retTypeIndex = defined $typeEntry ? $typeEntry->{index} : 0;

		my $i = 0;
		my $t = '';
		for my $arg (@$args) {
		    $t .= ', ' if $i++;
		    my $typeEntry = findTypeEntry( $arg->{ArgType} );
		    $t .= defined $typeEntry ? $typeEntry->{index} : 0;
		}
		my $arglist = $t eq '' ? 0 : $arglist{$t};
		die "arglist for $t not found" unless defined $arglist;
		if ( $m->{Flags} =~ "p" ) {
		    # Pure virtuals don't have a {case} number, that's normal
		    die "pure virtual $className\::$methName has a case number for sig=$sig" if defined $case;
		    $case = -1; # This remains -1, not 0 !
		} else {
		    die "$className\::$methName has no case number for sig=$sig" unless defined $case;
		}
		my $argcnt = $last + 1;
		my $methodFlags = '0';
		# Make no distinction between a static method in an ordinary class, or a method in a namespace
		$methodFlags .= "|Smoke::mf_static" if $m->{Flags} =~ "s" or $classNode->{NodeType} eq 'namespace';
		$methodFlags .= "|Smoke::mf_const" if $m->{Flags} =~ "c"; # useful?? probably not
		$methodFlags .= "|Smoke::mf_copyctor" if $m->{Flags} =~ "x";
		$methodFlags .= "|Smoke::mf_internal" if $m->{Flags} =~ "i";
		$methodFlags .= "|Smoke::mf_ctor" if $methName eq $className;
		$methodFlags .= "|Smoke::mf_dtor" if $m->{ReturnType} eq '~';
		$methodFlags .= "|Smoke::mf_protected" if $m->{Access} =~ /protected/;
		$methodFlags =~ s/0\|//; # beautify
		
		print OUT "\t{$classIndex, $methodIndex, $arglist, $argcnt, $methodFlags, $retTypeIndex, $case},\t//$methodCount $className\::$sig";
		print OUT " [pure virtual]" if ( $m->{Flags} =~ "p" ); # explain why $case = -1 ;)
		print OUT "\n";
		
		$allMethods{$className . "::" . $sig} = $methodCount;
		$methods[$methodCount] = {
					  c => $classIndex,
					  methIndex => $methodIndex,
					  argcnt => $argcnt,
					  args => $arglist,
					  retTypeIndex => $retTypeIndex,
					  idx => $case
					 };
		$methodCount++;
		$last--;
	    } # while
	} # if method
      } ); # Method Iter
    } ); # Class Iter
    print OUT "};\n\n";

    my @protos;
    Iter::LocalCompounds( $rootnode, sub {
	my $classNode = shift;
	my $className = join( "::", kdocAstUtil::heritage($classNode) );
	
	my $classIndex = $classidx{$className};
	print STDERR "writeSmokeDataFile: protos: looking at $className\n" if ($debug);

	Iter::MembersByType ( $classNode, undef,
		sub {	my ($classNode, $m ) = @_;

	if( $m->{NodeType} eq "enum" ) {
	    foreach my $enum ( @{$m->{ParamList}} ) {
		my $enumName = $enum->{ArgName};
		my $sig = "$className\::$enumName\()";
		my $xmeth = $allMethods{$sig};
		die "'Method' for enum $sig not found" unless defined $xmeth;
		my $xmethIndex = $methodidx{$enumName};
		die "'Method index' for enum $enumName not found" unless defined $xmethIndex;
		push @protos, {
			       methIndex => $xmethIndex,
			       c => $classIndex,
			       over => {
					$sig => {
						 sig => $sig,
						}
				       },
			       meth => $xmeth
			      };
	    }

	} elsif( $m->{NodeType} eq 'var' ) {

	    my $name = $m->{astNodeName};
	    my $fullName = "$className\::$name";
	    my $sig = "$fullName\()";
	    my $xmeth = $allMethods{$sig};
	    die "'Method' for var $sig not found" unless defined $xmeth;
	    my $xmethIndex = $methodidx{$name};
	    die "'Method index' for var $name not found" unless defined $xmethIndex;
	    push @protos, {
			       methIndex => $xmethIndex,
			       c => $classIndex,
			       over => {
					$sig => {
						 sig => $sig,
						}
				       },
			       meth => $xmeth
			  };

	}
		    });

	for my $p (keys %{ $classNode->{proto} }) {
	    # For each prototype
	    my $scratch = { %{ $classNode->{proto}{$p} } }; # sig->method association
	    # first, grab all the superclass voodoo
	    for my $supNode (superclass_list($classNode)) {
		my $i = $supNode->{proto}{$p};
		next unless $i;
		for my $k (keys %$i) {
		    $scratch->{$k} = $i->{$k} unless exists $scratch->{$k};
		}
	    }

	    # Ok, now we have a full list
	    #if(scalar keys %$scratch > 1) {
		#print STDERR "Overload: $p (@{[keys %$scratch]})\n" if ($debug);
	    #}
	    my $xmethIndex = $methodidx{$p};
	    my $classIndex = $classidx{$className};
	    for my $sig (keys %$scratch) {
		#my $xsig = $scratch->{$sig}{class} . "::" . $sig;
		my $xsig = $className . "::" . $sig;
		$scratch->{$sig}{sig} = $xsig;
		delete $scratch->{$sig}
		    if $scratch->{$sig}{Flags} =~ "p" # pure virtual
			or not exists $allMethods{$xsig};
	    }
	    push @protos, {
		methIndex => $xmethIndex,
		c => $classIndex,
		over => $scratch
	    } if scalar keys %$scratch;
	}
    });

    my @protolist = sort { $a->{c} <=> $b->{c} || $a->{methIndex} <=> $b->{methIndex} } @protos;
#for my $abc (@protos) {
#print "$abc->{methIndex}.$abc->{c}\n";
#}

    print STDERR "Writing methodmap table\n" if ($debug);
    my @resolve = ();
    print OUT "// Class ID, munged name ID (index into methodNames), method def (see methods) if >0 or number of overloads if <0\n";
    my $methodMapCount = 1;
    print OUT "static Smoke::MethodMap ${libname}_methodMaps[] = {\n";
    print OUT "\t{ 0, 0, 0 },\t//0 (no method)\n";
    for my $cur (@protolist) {
	if(scalar keys %{ $cur->{over} } > 1) {
	    print OUT "\t{$cur->{c}, $cur->{methIndex}, -@{[1+scalar @resolve]}},\t//$methodMapCount $classlist[$cur->{c}]\::$methodlist[$cur->{methIndex}]\n";
	    $methodMapCount++;
	    for my $k (keys %{ $cur->{over} }) {
	        my $p = $cur->{over}{$k};
	        my $xsig = $p->{class} ? "$p->{class}\::$k" : $p->{sig};
	        push @resolve, { k => $k, p => $p, cur => $cur, id => $allMethods{$xsig} };
	    }
	    push @resolve, 0;
	} else {
	    for my $k (keys %{ $cur->{over} }) {
	        my $p = $cur->{over}{$k};
	        my $xsig = $p->{class} ? "$p->{class}\::$k" : $p->{sig};
	        print OUT "\t{$cur->{c}, $cur->{methIndex}, $allMethods{$xsig}},\t//$methodMapCount $classlist[$cur->{c}]\::$methodlist[$cur->{methIndex}]\n";
	        $methodMapCount++;
	    }
	}
    }
    print OUT "};\n\n";


    print STDERR "Writing ambiguousMethodList\n" if ($debug);
    print OUT "static Smoke::Index ${libname}_ambiguousMethodList[] = {\n";
    print OUT "    0,\n";
    for my $r (@resolve) {
	unless($r) {
	    print OUT "    0,\n";
	    next;
	}
	my $xsig = $r->{p}{class} ? "$r->{p}{class}\::$r->{k}" : $r->{p}{sig};
	die "ambiguousMethodList: no method found for $xsig\n" if !defined $allMethods{$xsig};
	print OUT "    $allMethods{$xsig},  // $xsig\n";
    }
    print OUT "};\n\n";

#    print OUT "extern \"C\" { // needed?\n";
#    print OUT "    void init_${libname}_Smoke();\n";
#    print OUT "}\n";
    print OUT "\n";
    print OUT "Smoke* qt_Smoke = 0L;\n";
    print OUT "\n";
    print OUT "// Create the Smoke instance encapsulating all the above.\n";
    print OUT "void init_${libname}_Smoke() {\n";
    print OUT "    qt_Smoke = new Smoke(\n";
    print OUT "        ${libname}_classes, ".$#classlist.",\n";
    print OUT "        ${libname}_methods, $methodCount,\n";
    print OUT "        ${libname}_methodMaps, $methodMapCount,\n";
    print OUT "        ${libname}_methodNames, $methodNameCount,\n";
    print OUT "        ${libname}_types, $typeCount,\n";
    print OUT "        ${libname}_inheritanceList,\n";
    print OUT "        ${libname}_argumentList,\n";
    print OUT "        ${libname}_ambiguousMethodList,\n";
    print OUT "        ${libname}_cast );\n";
    print OUT "}\n";
    close OUT;

#print "@{[keys %allMethods ]}\n";
}

1;
