def error_log(logger, e, message=None):
    logger.error(e)
    if message:
        logger.error(message)


def info_log(logger, info, message=None):
    logger.info(info)
    if message:
        logger.info(message)
