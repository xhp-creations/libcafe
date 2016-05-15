#include <wiiu.h>

#include <sys/iosupport.h>
#include <sys/syslimits.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

static FSClient* fsClient = NULL;
static FSCmdBlock* fsCmdBlock = NULL;

static void FSDrvReportError(struct _reent* r) {
    FSError error = FSGetLastError(fsClient);
    switch(error) {
        case FS_ERROR_NOT_INIT:
            r->_errno = EINVAL;
            break;
        case FS_ERROR_BUSY:
            r->_errno = EBUSY;
            break;
        case FS_ERROR_CANCELED:
            r->_errno = ECANCELED;
            break;
        case FS_ERROR_END_OF_DIRECTORY:
            break;
        case FS_ERROR_END_OF_FILE:
            break;
        case FS_ERROR_MAX_MOUNTPOINTS:
            r->_errno = ENOMEM;
            break;
        case FS_ERROR_MAX_VOLUMES:
            r->_errno = ENOMEM;
            break;
        case FS_ERROR_MAX_CLIENTS:
            r->_errno = ENOMEM;
            break;
        case FS_ERROR_MAX_FILES:
            r->_errno = EMFILE;
            break;
        case FS_ERROR_MAX_DIRS:
            r->_errno = ENOMEM;
            break;
        case FS_ERROR_ALREADY_OPEN:
            r->_errno = EBUSY;
            break;
        case FS_ERROR_ALREADY_EXISTS:
            r->_errno = EEXIST;
            break;
        case FS_ERROR_NOT_FOUND:
            r->_errno = ENOENT;
            break;
        case FS_ERROR_NOT_EMPTY:
            r->_errno = ENOTEMPTY;
            break;
        case FS_ERROR_ACCESS_ERROR:
            r->_errno = EINVAL;
            break;
        case FS_ERROR_PERMISSION_ERROR:
            r->_errno = EACCES;
            break;
        case FS_ERROR_DATA_CORRUPTED:
            r->_errno = EIO;
            break;
        case FS_ERROR_STORAGE_FULL:
            r->_errno = ENOSPC;
            break;
        case FS_ERROR_JOURNAL_FULL:
            r->_errno = ENOSPC;
            break;
        case FS_ERROR_UNAVAILABLE_CMD:
            r->_errno = ENOSYS;
            break;
        case FS_ERROR_UNSUPPORTED_CMD:
            r->_errno = ENOSYS;
            break;
        case FS_ERROR_INVALID_PARAM:
            r->_errno = EINVAL;
            break;
        case FS_ERROR_INVALID_PATH:
            r->_errno = EINVAL;
            break;
        case FS_ERROR_INVALID_BUFFER:
            r->_errno = EINVAL;
            break;
        case FS_ERROR_INVALID_ALIGNMENT:
            r->_errno = EINVAL;
            break;
        case FS_ERROR_INVALID_CLIENT_HANDLE:
            r->_errno = EINVAL;
            break;
        case FS_ERROR_INVALID_FILE_HANDLE:
            r->_errno = EINVAL;
            break;
        case FS_ERROR_INVALID_DIR_HANDLE:
            r->_errno = EINVAL;
            break;
        case FS_ERROR_NOT_FILE:
            r->_errno = EISDIR;
            break;
        case FS_ERROR_NOT_DIR:
            r->_errno = ENOTDIR;
            break;
        case FS_ERROR_FILE_TOO_BIG:
            r->_errno = EFBIG;
            break;
        case FS_ERROR_OUT_OF_RANGE:
            r->_errno = ERANGE;
            break;
        case FS_ERROR_OUT_OF_RESOURCES:
            r->_errno = ENOMEM;
            break;
        case FS_ERROR_MEDIA_NOT_READY:
            r->_errno = EAGAIN;
            break;
        case FS_ERROR_MEDIA_ERROR:
            r->_errno = EIO;
            break;
        case FS_ERROR_WRITE_PROTECTED:
            r->_errno = EACCES;
            break;
        case FS_ERROR_INVALID_MEDIA:
            r->_errno = EINVAL;
            break;
        case FS_ERROR_FATAL:
            r->_errno = EIO;
            break;
        default:
            r->_errno = EIO;
            break;
    }
}

static void FSDrvConvertStat(struct stat* st, FSStat* fsStat) {
    st->st_dev = 0;
    st->st_ino = 0;
    st->st_mode = fsStat->permission | ((fsStat->flag & FS_STAT_FLAG_IS_DIRECTORY) ? S_IFDIR : S_IFREG);
    st->st_nlink = 1;
    st->st_uid = (uid_t) fsStat->ownerId;
    st->st_gid = (gid_t) fsStat->groupId;
    st->st_rdev = 0;
    st->st_size = fsStat->size;
    st->st_atime = 0;
    st->st_mtime = (time_t) (fsStat->modifiedTime / 1000000 + 315532800);
    st->st_ctime = (time_t) (fsStat->createdTime / 1000000 + 315532800);
    st->st_blksize = 0;
    st->st_blocks = 0;
}

static int FSDrvOpen(struct _reent* r, void* fileStruct, const char* path, int flags, int mode) {
    FSFileHandle* handle = (FSFileHandle*) fileStruct;

    char modeString[3] = {'\0'};
    switch(flags) {
        case O_RDONLY:
            snprintf(modeString, sizeof(modeString), "r");
            break;
        case O_WRONLY | O_CREAT | O_TRUNC:
            snprintf(modeString, sizeof(modeString), "w");
            break;
        case O_WRONLY | O_CREAT | O_APPEND:
            snprintf(modeString, sizeof(modeString), "a");
            break;
        case O_RDWR:
            snprintf(modeString, sizeof(modeString), "r+");
            break;
        case O_RDWR | O_CREAT | O_TRUNC:
            snprintf(modeString, sizeof(modeString), "w+");
            break;
        case O_RDWR | O_CREAT | O_APPEND:
            snprintf(modeString, sizeof(modeString), "a+");
            break;
        default:
            r->_errno = EINVAL;
            return -1;
    }

    FSStatus err = FSOpenFile(fsClient, fsCmdBlock, path, modeString, handle, FS_RET_ALL_ERROR);
    if(err != FS_STATUS_OK) {
        FSDrvReportError(r);
        return -1;
    }

    return 0;
}

static int FSDrvClose(struct _reent* r, int fd) {
    FSFileHandle* handle = (FSFileHandle*) fd;

    FSStatus err = FSCloseFile(fsClient, fsCmdBlock, *handle, FS_RET_ALL_ERROR);
    if(err != FS_STATUS_OK) {
        FSDrvReportError(r);
        return -1;
    }

    return 0;
}

static ssize_t FSDrvWrite(struct _reent* r, int fd, const char* ptr, size_t len) {
    FSFileHandle* handle = (FSFileHandle*) fd;

    const void* buf = ptr;
    if(((u32) ptr & (FS_IO_BUFFER_ALIGN - 1)) != 0) {
        buf = memalign(FS_IO_BUFFER_ALIGN, len);
        if(buf == NULL) {
            r->_errno = ENOMEM;
            return -1;
        }

        memcpy((void*) buf, ptr, len);
    }

    FSStatus err = FSWriteFile(fsClient, fsCmdBlock, buf, 1, len, *handle, FS_IO_FLAG_NONE, FS_RET_ALL_ERROR);

    if(((u32) ptr & (FS_IO_BUFFER_ALIGN - 1)) != 0) {
        free((void*) buf);
    }

    if(err < FS_STATUS_OK) {
        FSDrvReportError(r);
        return -1;
    }

    return err;
}

static ssize_t FSDrvRead(struct _reent* r, int fd, char* ptr, size_t len) {
    FSFileHandle* handle = (FSFileHandle*) fd;

    void* buf = ptr;
    if(((u32) ptr & (FS_IO_BUFFER_ALIGN - 1)) != 0) {
        buf = memalign(FS_IO_BUFFER_ALIGN, len);
        if(buf == NULL) {
            r->_errno = ENOMEM;
            return -1;
        }
    }

    FSStatus err = FSReadFile(fsClient, fsCmdBlock, buf, 1, len, *handle, FS_IO_FLAG_NONE, FS_RET_ALL_ERROR);

    if(((u32) ptr & (FS_IO_BUFFER_ALIGN - 1)) != 0) {
        if(err >= FS_STATUS_OK) {
            memcpy(ptr, buf, (size_t) err);
        }

        free(buf);
    }

    if(err < FS_STATUS_OK) {
        FSDrvReportError(r);
        return -1;
    }

    return err;
}

static off_t FSDrvSeek(struct _reent* r, int fd, off_t pos, int dir) {
    FSFileHandle* handle = (FSFileHandle*) fd;

    FSStatus err = FS_STATUS_OK;

    switch(dir) {
        case SEEK_SET:
            break;
        case SEEK_CUR: {
            u32 currPos = 0;
            if((err = FSGetPosFile(fsClient, fsCmdBlock, *handle, &currPos, FS_RET_ALL_ERROR)) == FS_STATUS_OK) {
                pos += currPos;
            }

            break;
        }
        case SEEK_END: {
            FSStat stat;
            if((err = FSGetStatFile(fsClient, fsCmdBlock, *handle, &stat, FS_RET_ALL_ERROR)) == FS_STATUS_OK) {
                pos += stat.size;
            }

            break;
        }
        default:
            r->_errno = EINVAL;
            return -1;
    }

    if(err == FS_STATUS_OK) {
        if(pos < 0) {
            r->_errno = EINVAL;
            return -1;
        }

        err = FSSetPosFile(fsClient, fsCmdBlock, *handle, (u32) pos, FS_RET_ALL_ERROR);
    }

    if(err != FS_ERROR_OK) {
        FSDrvReportError(r);
        return -1;
    }

    return 0;
}

static int FSDrvFStat(struct _reent* r, int fd, struct stat* st) {
    FSFileHandle* handle = (FSFileHandle*) fd;

    FSStat stat;
    FSStatus err = FSGetStatFile(fsClient, fsCmdBlock, *handle, &stat, FS_RET_ALL_ERROR);
    if(err == FS_STATUS_OK) {
        FSDrvConvertStat(st, &stat);
    } else {
        FSDrvReportError(r);
        return -1;
    }

    return 0;
}

static int FSDrvStat(struct _reent* r, const char* file, struct stat* st) {
    FSStat stat;
    FSStatus err = FSGetStat(fsClient, fsCmdBlock, file, &stat, FS_RET_ALL_ERROR);
    if(err == FS_STATUS_OK) {
        FSDrvConvertStat(st, &stat);
    } else {
        FSDrvReportError(r);
        return -1;
    }

    return 0;
}

static int FSDrvLink(struct _reent* r, const char* existing, const char* newLink) {
    r->_errno = ENOSYS;
    return -1;
}

static int FSDrvUnlink(struct _reent* r, const char* name) {
    FSStatus err = FSRemove(fsClient, fsCmdBlock, name, FS_RET_ALL_ERROR);
    if(err != FS_STATUS_OK) {
        FSDrvReportError(r);
        return -1;
    }

    return 0;
}

static int FSDrvChdir(struct _reent* r, const char* name) {
    FSStatus err = FSChangeDir(fsClient, fsCmdBlock, name, FS_RET_ALL_ERROR);
    if(err != FS_STATUS_OK) {
        FSDrvReportError(r);
        return -1;
    }

    return 0;
}

static int FSDrvRename(struct _reent* r, const char* oldName, const char* newName) {
    FSStatus err = FSRename(fsClient, fsCmdBlock, oldName, newName, FS_RET_ALL_ERROR);
    if(err != FS_STATUS_OK) {
        FSDrvReportError(r);
        return -1;
    }

    return 0;
}

static int FSDrvMkdir(struct _reent* r, const char* path, int mode) {
    FSStatus err = FSMakeDir(fsClient, fsCmdBlock, path, FS_RET_ALL_ERROR);
    if(err != FS_STATUS_OK) {
        FSDrvReportError(r);
        return -1;
    }

    return 0;
}

static DIR_ITER* FSDrvDirOpen(struct _reent* r, DIR_ITER* dirState, const char* path) {
    FSDirHandle* handle = (FSDirHandle*) dirState->dirStruct;

    FSStatus err = FSOpenDir(fsClient, fsCmdBlock, path, handle, FS_RET_ALL_ERROR);
    if(err != FS_STATUS_OK) {
        FSDrvReportError(r);
        return NULL;
    }

    return dirState;
}

static int FSDrvDirReset(struct _reent* r, DIR_ITER* dirState) {
    FSDirHandle* handle = (FSDirHandle*) dirState->dirStruct;

    FSStatus err = FSRewindDir(fsClient, fsCmdBlock, *handle, FS_RET_ALL_ERROR);
    if(err != FS_STATUS_OK) {
        FSDrvReportError(r);
        return -1;
    }

    return 0;
}

static int FSDrvDirNext(struct _reent* r, DIR_ITER* dirState, char* filename, struct stat* filestat) {
    FSDirHandle* handle = (FSDirHandle*) dirState->dirStruct;

    FSDirEntry dirEntry;
    FSStatus err = FSReadDir(fsClient, fsCmdBlock, *handle, &dirEntry, FS_RET_ALL_ERROR);
    if(err == FS_STATUS_OK) {
        strncpy(filename, dirEntry.name, NAME_MAX);

        FSDrvConvertStat(filestat, &dirEntry.stat);
    } else {
        FSDrvReportError(r);
        return -1;
    }

    return 0;
}

static int FSDrvDirClose(struct _reent* r, DIR_ITER* dirState) {
    FSDirHandle* handle = (FSDirHandle*) dirState->dirStruct;

    FSStatus err = FSCloseDir(fsClient, fsCmdBlock, *handle, FS_RET_ALL_ERROR);
    if(err != FS_STATUS_OK) {
        FSDrvReportError(r);
        return -1;
    }

    return 0;
}

static int FSDrvStatVFS(struct _reent* r, const char* path, struct statvfs* buf) {
    r->_errno = ENOSYS;
    return -1;
}

static int FSDrvFTruncate(struct _reent* r, int fd, off_t len) {
    FSFileHandle* handle = (FSFileHandle*) fd;

    FSStatus err = FS_STATUS_OK;

    u32 currPos = 0;
    if((err = FSGetPosFile(fsClient, fsCmdBlock, *handle, &currPos, FS_RET_ALL_ERROR)) == FS_STATUS_OK
       && (err = FSSetPosFile(fsClient, fsCmdBlock, *handle, (u32) len, FS_RET_ALL_ERROR)) == FS_STATUS_OK) {
        err = FSTruncateFile(fsClient, fsCmdBlock, *handle, FS_RET_ALL_ERROR);

        FSStatus restoreErr = FSSetPosFile(fsClient, fsCmdBlock, *handle, currPos, FS_RET_ALL_ERROR);
        if(err == FS_STATUS_OK) {
            err = restoreErr;
        }
    }

    if(err != FS_ERROR_OK) {
        FSDrvReportError(r);
        return -1;
    }

    return 0;
}

static int FSDrvFSync(struct _reent* r, int fd) {
    FSFileHandle* handle = (FSFileHandle*) fd;

    FSStatus err = FSFlushFile(fsClient, fsCmdBlock, *handle, FS_RET_ALL_ERROR);
    if(err != FS_STATUS_OK) {
        FSDrvReportError(r);
        return -1;
    }

    return 0;
}

static int FSDrvChmod(struct _reent* r, const char* path, mode_t mode) {
    r->_errno = ENOSYS;
    return -1;
}

static int FSDrvFChmod(struct _reent* r, int fd, mode_t mode) {
    r->_errno = ENOSYS;
    return -1;
}

static devoptab_t fsDrvOpTab = {
        .name         = "fs",
        .structSize   = sizeof(FSFileHandle),
        .open_r       = FSDrvOpen,
        .close_r      = FSDrvClose,
        .write_r      = FSDrvWrite,
        .read_r       = FSDrvRead,
        .seek_r       = FSDrvSeek,
        .fstat_r      = FSDrvFStat,
        .stat_r       = FSDrvStat,
        .link_r       = FSDrvLink,
        .unlink_r     = FSDrvUnlink,
        .chdir_r      = FSDrvChdir,
        .rename_r     = FSDrvRename,
        .mkdir_r      = FSDrvMkdir,
        .dirStateSize = sizeof(FSDirHandle),
        .diropen_r    = FSDrvDirOpen,
        .dirreset_r   = FSDrvDirReset,
        .dirnext_r    = FSDrvDirNext,
        .dirclose_r   = FSDrvDirClose,
        .statvfs_r    = FSDrvStatVFS,
        .ftruncate_r  = FSDrvFTruncate,
        .fsync_r      = FSDrvFSync,
        .deviceData   = NULL,
        .chmod_r      = FSDrvChmod,
        .fchmod_r     = FSDrvFChmod
};

void FSDrvInit(FSClient* client, FSCmdBlock* cmdBlock) {
    if(client == NULL || cmdBlock == NULL || (fsClient != NULL && fsCmdBlock != NULL)) {
        return;
    }

    fsClient = client;
    fsCmdBlock = cmdBlock;

    int dev = AddDevice(&fsDrvOpTab);
    if(dev != -1) {
        setDefaultDevice(dev);
    }
}

void FSDrvShutdown() {
    RemoveDevice(fsDrvOpTab.name);
    setDefaultDevice(0);

    fsClient = NULL;
    fsCmdBlock = NULL;
}